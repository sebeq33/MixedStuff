import java.awt.image.*;
import javax.imageio.*;
import java.io.*;

/**
 * Simple utility class with static methods to load and save images.
 *
 * Can read images in GIF, JPG and PNG format.
 * Can write images in JPG or PNG format.
 *
 * Based on class ImageFileManager described in chapter 11 of the book
 * "Objects First with Java" by David J Barnes and Michael Kolling
 * (from 2nd edition onwards).
 *
 * @author  Michael Kolling, David J Barnes and Peter Kenny
 * @version 1.0
 */

public class ImageFileManager
{
    /**
     * Read an image file from disk and return it as an image.
     * This method can read various formats including GIF, JPG and PNG.
     * @param file The image file to be loaded
     * @return The image object
     * @throws IOException if operation fails
     */

    public static ColorImage loadImage(File file) throws IOException
    {
        BufferedImage image = ImageIO.read(file);
        if (image == null || image.getWidth(null) < 1)
            throw new IOException("Unsupported format");
        return new ColorImage(image);
    }

    /**
     * Write an image file to disk
     * @param image The image to be saved
     * @param file The file to save to
     * @throws IOException if operation fails
     */

    public static void saveImage(ColorImage image, File file) throws IOException
    {
        String name = file.getName();
        int dot = name.lastIndexOf('.');
        if (dot < 0 || dot == name.length()-1)
            throw new IOException("File type missing \"" + name + "\"");
        String format = name.substring(dot+1);
        boolean knownFormat = ImageIO.getImageWritersByFormatName(format).hasNext();
        if (!knownFormat)
            throw new IOException("Unsupported format \"" + format + "\"");
        ImageIO.write(image, format, file);
    }

}
