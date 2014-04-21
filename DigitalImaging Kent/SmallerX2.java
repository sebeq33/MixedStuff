/**
 * Make image smaller by a factor of 2.
 *
 * Based on code from class ImageViewer described in chapter 11 of
 * "Objects First with Java" by David J Barnes and Michael Kolling
 * (from 2nd edition onwards).
 *
 * @author  Michael Kolling, David J Barnes and Peter Kenny
 * @version 1.0
 */

public class SmallerX2 extends Filter
{
    /**
     * Constructor
     * @param name The name of the filter
     */

    public SmallerX2(String name)
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
        // Create new image with half size

        int height = image.getHeight() / 2;
        int width = image.getWidth() / 2;
        ColorImage newImage = new ColorImage(width, height);

        // Copy pixel data into new image (pixel replication)

        for (int y=0; y<height; y++)
            for (int x=0; x<width; x++)
                newImage.setPixel(x, y, image.getPixel(x*2, y*2));

        return newImage;
    }

}
