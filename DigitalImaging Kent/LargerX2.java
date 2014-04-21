import java.awt.Color;

/**
 * Make image larger by a factor of 2.
 *
 * Based on code from class ImageViewer described in chapter 11 of
 * "Objects First with Java" by David J Barnes and Michael Kolling
 * (from 2nd edition onwards).
 *
 * @author Michael Kolling, David J Barnes and Peter Kenny
 * @version 1.0
 */

public class LargerX2 extends Filter
{
    /**
     * Constructor
     * @param name The name of the filter
     */

    public LargerX2(String name)
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
        // Create new image with double size

        int height = image.getHeight();
        int width = image.getWidth();
        ColorImage newImage = new ColorImage(width*2, height*2);

        // Copy pixel data into new image (pixel replication)

        for (int y=0; y<height; y++) {
            for (int x=0; x<width; x++) {
                Color col = image.getPixel(x,y);
                newImage.setPixel(x*2,   y*2,   col);
                newImage.setPixel(x*2+1, y*2,   col);
                newImage.setPixel(x*2,   y*2+1, col);
                newImage.setPixel(x*2+1, y*2+1, col);
            }
        }

        return newImage;
    }

}
