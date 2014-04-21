import java.awt.Color;

/**
 * Apply histogram equalization to a monochrome image.
 * (In a monochrome image all pixels are shades of grey, i.e. red=green=blue.)
 *
 * @author  add your name here
 * @version 1.0
 */

public class EqualizeMono extends Filter
{
    /**
     * Constructor
     * @param name The name of the filter
     */

    public EqualizeMono(String name)
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
    	
    	//calculate the histogram
        int[] histogram = new int[maxIntensity + 1];
        for (int x = 0; x < image.getWidth(); ++x)
    		for (int y = 0; y < image.getHeight(); ++y)
    			histogram[image.getPixel(x, y).getBlue()]++; //using blue because red, green and blue are equal and represent the intensity
        
        int sum = 0;
        //calculating new colors and normalize histogram using previous arrays
        //only doing calculation ((maxIntensity + 1) * 1 colors) times and not in each pixel of the image
        for (int i = 0; i < maxIntensity + 1; ++i)
        {
        	sum += histogram[i];
        	histogram[i] = (sum * maxIntensity) / (image.getHeight() * image.getWidth());
        }
        
        for (int x = 0; x < image.getWidth(); ++x)
    		for (int y = 0; y < image.getHeight(); ++y)
    		{
    			int intensity = histogram[image.getPixel(x, y).getBlue()];
    			//Accessing new color in histogram and replace it
    			image.setPixel(x, y, new Color(intensity, intensity, intensity, image.getPixel(x, y).getAlpha()));
    		}
        
        return image;
    }

}

