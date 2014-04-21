import java.awt.Color;

/**
 * Remove colour from image.
 * Each pixel is set to a shade of grey of an equivalent luminance
 * taking into account human eye's relative sensitivity to R, G and B.
 *
 * Based on class GrayScaleFilter described in chapter 11 of the book
 * "Objects First with Java" by David J Barnes and Michael Kolling
 * (from 2nd edition onwards).
 *
 * @author  Michael Kolling, David J Barnes and Peter Kenny
 * @version 1.0
 */

public class GreyScale extends Filter
{
	/**
	 * Constructor
	 * @param name The name of the filter
	 */

	public GreyScale(String name)
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
                Color pix = image.getPixel(x, y);
                int lum = (int) Math.round(0.299*pix.getRed()
                                         + 0.587*pix.getGreen()
                                         + 0.114*pix.getBlue());
                image.setPixel(x, y, new Color(lum, lum, lum));
            }
        }
        return image;
    }

}
