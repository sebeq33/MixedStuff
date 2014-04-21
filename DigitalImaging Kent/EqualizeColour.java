import java.awt.Color;

/**
 * Apply histogram equalization to a colour image.
 * (Enhance intensity contrast without changing chromaticity.)
 *
 * @author  add your name here
 * @version 1.0
 */

public class EqualizeColour extends Filter
{
    /**
     * Constructor
     * @param name The name of the filter
     */

    public EqualizeColour(String name)
    {
        super(name);
    }

    /**
     * Apply this filter to an image
     * @param image The image to be changed by this filter
     * @return The filtered image
     */

    public ColorImage apply(ColorImage image)
    {
    	//8 bits by colors, ColorImage can only be TYPE_INT_RGB
    	int maxIntensity = 255;
    	
        int[] histogramRed = new int[maxIntensity + 1];
        int[] histogramGreen = new int[maxIntensity + 1];
        int[] histogramBlue = new int[maxIntensity + 1];
        
        //calculate the histograms
        for (int x = 0; x < image.getWidth(); ++x)
    		for (int y = 0; y < image.getHeight(); ++y)
    		{
    			histogramRed[image.getPixel(x, y).getRed()]++;
    			histogramGreen[image.getPixel(x, y).getGreen()]++;
    			histogramBlue[image.getPixel(x, y).getBlue()]++;
    		}
        
        int sumRed = 0;
        int sumGreen = 0;
        int sumBlue = 0;
        //calculating new colors and normalize histogram
        //only doing calculation ((maxIntensity + 1) * 3 colors) times and not in each pixel of the image
        for (int i = 0; i < maxIntensity + 1; ++i)
        {
        	sumRed += histogramRed[i];
        	sumGreen += histogramGreen[i];
        	sumBlue += histogramBlue[i];
        	
        	//replace histogram value by the new color for this intensity
        	//re-using previous arrays cells becoming useless
        	histogramRed[i] = (sumRed * maxIntensity) / (image.getHeight() * image.getWidth());
        	histogramGreen[i] = (sumGreen * maxIntensity) / (image.getHeight() * image.getWidth());
        	histogramBlue[i] = (sumBlue * maxIntensity) / (image.getHeight() * image.getWidth());
        }
        
        for (int x = 0; x < image.getWidth(); ++x)
    		for (int y = 0; y < image.getHeight(); ++y)
    		{
    			//Accessing new color in histogram and replace it
    			image.setPixel(x, y, new Color(
    					histogramRed[image.getPixel(x, y).getRed()],
    					histogramGreen[image.getPixel(x, y).getGreen()], 
    					histogramBlue[image.getPixel(x, y).getBlue()]));
    		}

        return image;
    }

}

