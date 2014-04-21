import java.awt.Color;

/**
 * Invert colours.
 *
 * Based on class InvertFilter described in chapter 11 of the book
 * "Objects First with Java" by David J Barnes and Michael Kolling
 * (from 2nd edition onwards).
 *
 * @author  Michael Kolling, David J. Barnes and Peter Kenny
 * @version 1.0
 */

public class Invert extends Filter
{
    /**
     * Constructor
     * @param name The name of the filter
     */

    public Invert(String name)
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
        for (int y=0; y<height; y++) {
            for (int x=0; x<width; x++) {
                Color pix = image.getPixel(x,y);
                image.setPixel(x, y, new Color(255-pix.getRed(),
                                               255-pix.getGreen(),
                                               255-pix.getBlue()));
            }
        }
        return image;
    }

}
