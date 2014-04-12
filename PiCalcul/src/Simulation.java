import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Random;
import java.util.concurrent.*;

/**
* This class calcul pi using Monte Carlo method and multi threads.
* @author Sebastien Bequignon (sb788)
* 
* Modif possible :
* using max 20000 points by threads
* ThreadLocalRandom
* Diff old and new value of Pi replacing averageDiff
* List of Future to cancel
* Increment total thrown points for final result
* 
* Exceptions :
* - Interupted exception : cancel Futures then interupt Thread.currentThread
* - ExecutionException : System.err.print(e.getCause())
*/

public class Simulation 
{
	private static class PiSimulation
	{
		private final int maxMilliSeconds = 20000; //20 sec max (in case of wrong arguments, too much)
		private int nbThread, pointsByThread;
		private double precision;
		private ArrayList<Integer> results;
		private ExecutorService exec;
		private CompletionService<Integer> completion;
		
		PiSimulation(int nbThread, int pointsByThread, double precision)
		{
			this.nbThread = nbThread;
			this.pointsByThread = pointsByThread;
			this.precision = precision;
		}
		
		private class PiWorker implements Callable<Integer> {
			private Random random;
			
			PiWorker(int workerNb)
			{
				//time is used to get a random seed and workerNb to differentiate the threads
				random = new Random(System.currentTimeMillis() + workerNb);
			}
		    public Integer call() 
		    {
		    	int success = 0;
				for (int j = 0; j < pointsByThread; j++)
				{ 
					double x = random.nextDouble(); 		//throw a point
			        double y = random.nextDouble();
					if ((x * x + y * y) < 1) 				// (bool)((x - center_x)^2 + (y - center_y)^2 < radius^2) mean in circle
						success++; 
				}
				return (success);
		    }
		}
		
		private boolean precisionReached() {
			ArrayList<Double> diffs = new ArrayList<Double>();
			double averageDiffByThread = 0;
			
			for (int i = 0; i < results.size() - 1; i += 2)
			{
				double piOne = (4 * ((double)results.get(i)) / pointsByThread);
				double piTwo = (4 * ((double)results.get(i + 1)) / pointsByThread);
				diffs.add(Math.abs(piOne - piTwo)); //get the difference between the two results
			}
			
			double precisionWantedByThread = (precision * (diffs.size())); //more results equal less precision by thread needed 
			for (int i = 0; i < diffs.size(); i++)
				averageDiffByThread += diffs.get(i);
			averageDiffByThread /= diffs.size();
			
//			System.out.println("CheckPrecision : precisionWanted = " + new DecimalFormat("#0.00000000").format(precision) + 
//					"  ||||  precisionWantedByThread = " + new DecimalFormat("#0.00000000").format(precisionWantedByThread) +
//					"  ||||  averageDiff = " + new DecimalFormat("#0.00000000").format(averageDiffByThread));

			return (averageDiffByThread < precisionWantedByThread);
		}
		
		public double getPi() {
			long startTime = System.currentTimeMillis();
			boolean completed = false;
			int nbWorker = 0;
			
			results = new ArrayList<Integer>();                        //get the results
			exec = Executors.newFixedThreadPool(nbThread);             //get nbThread available threads
			completion = new ExecutorCompletionService<Integer>(exec); //prepare completions work
			
			for (int i = 0; i < nbThread + 1; i++)
				completion.submit(new PiWorker(nbWorker++));           //put first workers
			
			while (!completed && (System.currentTimeMillis() - startTime) < maxMilliSeconds) //work loop
			{
				try {
					Future<Integer> ended = completion.take();         //wait at least one finished thread
					results.add(ended.get());                          //fill results
					completion.submit(new PiWorker(nbWorker++));       //put back a worker
					
					while ((ended = completion.poll()) != null)        //get other finished workers but don't wait
					{
						results.add(ended.get());                      //fill results
						completion.submit(new PiWorker(nbWorker++));   //put back a worker
					}
				} catch (InterruptedException | ExecutionException e) { e.printStackTrace(); } 
				
				//check precision if at least the asked number of threads are finished
				if (results.size() >= nbThread && results.size() > 2) 
					completed = precisionReached();
			}
			exec.shutdown();
			
			int inCircle = 0;
			for (int i = 0; i < results.size(); i++)
				inCircle += results.get(i);
			
			System.out.println("Finished : " + results.size() + " PiWorkers |||| " 
			+ (results.size() * pointsByThread) + " points |||| inCircle = " + inCircle);
			
			return (4 * ((double)(inCircle)) / (results.size() * pointsByThread)); // pi = (4 * success / thrownDarts)
		}
		
		public static double getPiProcedural(int points)
		{
			int inCircle = 0;
			for (int i = 0; i < points; i++)
			{
				double x = Math.random(); //between 0.0 and 1.0 (already thread-safe)
		        double y = Math.random();
				if ((x * x + y * y) < 1) // (bool)((x - center_x)^2 + (y - center_y)^2 < radius^2) mean in circle
					inCircle++;
			}
			return (4 * ((double) inCircle) / points);
		}
		
		public static void simulate(int nbThread, int PointsByThread, double precision, int repetition)
		{
			//print how much time take procedural Pi calculation
			long startTime = System.nanoTime();
			double pi = PiSimulation.getPiProcedural(PointsByThread * nbThread);
			long endTime = System.nanoTime();
			
			System.out.println("Pi Procedural = " + pi + "  ||||  Elapsed time = " + ((double)(endTime - startTime) / 1000000000) + " Seconds");
			System.out.print('\n');
			
			for (int i = 0; i < repetition; i++)
			{
				System.out.println("* Start Simulation ! MaxThreads = " + nbThread + "  |||  PointsByThread = " + PointsByThread);
				PiSimulation simulation = new PiSimulation(nbThread, PointsByThread, precision);
				
				startTime = System.nanoTime();
				pi = simulation.getPi();
				endTime = System.nanoTime();
				
				System.out.println("Pi using Threads = " + pi + "  ||||  Elapsed time = " + ((double)(endTime - startTime) / 1000000000) + " Seconds");
				System.out.println("-----------------------");
			}
			System.out.println("* End simulation");
		}
	}
	
    public static void main(String[] args) 
    {
    	//default values
    	int nbThread = 1;//Runtime.getRuntime().availableProcessors();
    	int PointsByThread = 1000000;
    	double precision = 0.0001;
    	int repetition = 6;
    	
    	if (args.length > 0) PointsByThread = Integer.parseInt(args[0]);
    	if (args.length > 1) nbThread = Integer.parseInt(args[1]);
    	if (args.length > 2) precision = Double.parseDouble(args[2]);
    	if (args.length > 3) repetition = Integer.parseInt(args[3]);
    	
    	PiSimulation.simulate(nbThread, PointsByThread, precision, repetition);
    }
}
