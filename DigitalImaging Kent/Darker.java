/**
 * Make image a bit darker.
 *
 * Based on class DarkerFilter described in chapter 11 of the book
 * "Objects First with Java" by David J Barnes and Michael Kolling
 * (from 2nd edition onwards).
 *
 * @author  Michael Kolling, David J Barnes and Peter Kenny
 * @version 1.0
 */

public class Darker extends Filter
{
    /**
     * Constructor
     * @param name The name of the filter
     */

    public Darker(String name)
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
        int height = image.getHeight();
        int width = image.getWidth();
        for (int y=0; y<height; y++)
            for (int x=0; x<width; x++)
                image.setPixel(x, y, image.getPixel(x,y).darker());
        return image;
    }

}

