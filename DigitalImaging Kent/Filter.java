/**
 * Abstract superclass for all image filters in this application.
 * Filters can be applied to ColorImages by invoking the apply method.
 *
 * Based on class Filter described in chapter 11 of the book
 * "Objects First with Java" by David J Barnes and Michael Kolling
 * (from 2nd edition onwards).
 *
 * @author  Michael Kolling, David J Barnes and Peter Kenny
 * @version 1.0
 */

public abstract class Filter
{
    private String name;

    /**
     * Create a new filter with a given name
     * @param name The name of the filter
     */

    public Filter(String name)
    {
        this.name = name;
    }

    /**
     * Return the name of this filter
     * @return  The name of this filter
     */

    public String getName()
    {
        return name;
    }

    /**
     * Apply this filter to an image
     * @param image The image to be changed by this filter
     * @return The filtered image (may be same or new object, null=no result)
     */

    public abstract ColorImage apply(ColorImage image);

}

