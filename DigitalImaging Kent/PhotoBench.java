import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import javax.swing.*;

import java.io.File;
import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;

/**
 * PhotoBench is the main class of the digital imaging coursework
 * assignment for CO641.  It builds and displays the application GUI
 * and initialises all other components.
 * <p>
 * This application and supporting classes can be compiled and run
 * using any IDE or just the command line of DOS/Linux/etc.  If using
 * BlueJ create an object of class PhotoBench to run the application
 *(<i>note - the GUI may open behind the BlueJ window</i>).
 * <p>
 * Based on class ImageViewer described in chapter 11 of the book
 * "Objects First with Java" by David J Barnes and Michael Kolling
 * (from 2nd edition onwards).
 *
 * @author  Michael Kolling, David J Barnes and Peter Kenny
 * @version 2013-14
 */

public class PhotoBench
{
    // Fields ----------------------------------------------------------

    private static final String VERSION = "Version 2013-14";
    private static JFileChooser fileChooser
        = new JFileChooser(System.getProperty("user.dir"));

    private JFrame frame;
    private ImagePanel imagePanel;
    private JLabel filenameLabel;
    private JLabel statusLabel;
    private ColorImage currentImage;
    private List<Filter> resizeFilters;
    private List<Filter> colourReductionFilters;
    private List<Filter> contrastFilters;

    // Constructors ----------------------------------------------------

    /**
     * Create PhotoBench GUI and show it on screen
     */

    public PhotoBench()
    {
        currentImage = null;
        resizeFilters = createResizeFilters();
        colourReductionFilters = createColourReductionFilters();
        contrastFilters = createContrastFilters();
        makeFrame();
    }

    // Menu function implementations -----------------------------------

    /**
     * Open function: open a file chooser to select a new image file,
     * and then display the chosen image.
     */

    private void openFile()
    {
        int returnVal = fileChooser.showOpenDialog(frame);
        if (returnVal == JFileChooser.APPROVE_OPTION) {
            File selectedFile = fileChooser.getSelectedFile();
            try {
                currentImage = ImageFileManager.loadImage(selectedFile);
                imagePanel.setImage(currentImage);
                showFilename(selectedFile.getPath());
                showStatus("File loaded");
                frame.pack();
            } catch (Exception e) {
                JOptionPane.showMessageDialog(frame, e.getMessage(),
                    "Image Load Error", JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    /**
     * Close function: close the current image
     */

    private void close()
    {
        currentImage = null;
        imagePanel.clearImage();
        showFilename(null);
    }

    /**
     * Save As function: save the current image to a file
     */

    private void saveAs()
    {
        if (currentImage != null) {
            int returnVal = fileChooser.showSaveDialog(frame);
            if (returnVal == JFileChooser.APPROVE_OPTION) {
                File selectedFile = fileChooser.getSelectedFile();
                try {
                    ImageFileManager.saveImage(currentImage, selectedFile);
                    showFilename(selectedFile.getPath());
                } catch (Exception e) {
                    JOptionPane.showMessageDialog(frame, e.getMessage(),
                        "Image Save Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        }
    }

    /**
     * Quit function: quit the application
     */

    private void quit()
    {
        System.exit(0);
    }

    /**
     * Apply a given filter to the current image
     * @param filter The filter to be applied
     */

    private void applyFilter(Filter filter)
    {
        if (currentImage != null) {
            ColorImage result = filter.apply(currentImage);
            if (result != null) {
                currentImage = result;
                imagePanel.setImage(currentImage);
                frame.pack();
                frame.repaint();
                showStatus("Applied: " + filter.getName());
            }
        }
        else {
            showStatus("No image loaded");
        }
    }

    /**
     * 'About' function: show the 'about' box
     */

    private void showAbout()
    {
        JOptionPane.showMessageDialog(frame,
                    "PhotoBench\n" + VERSION,
                    "About PhotoBench",
                    JOptionPane.INFORMATION_MESSAGE);
    }

    // Support methods -------------------------------------------------

    /**
     * Display a file name on the appropriate label
     * @param filename The file name to be displayed
     */

    private void showFilename(String filename)
    {
        if (filename == null)
            filenameLabel.setText("No file displayed");
        else
            filenameLabel.setText("File: " + filename);
    }

    /**
     * Display a status message in the frame's status bar
     */

    private void showStatus(String text)
    {
        statusLabel.setText(text);
    }

    /**
     * Create and return a list of the resize filters
     * @return The list of filters
     */

    private List<Filter> createResizeFilters()
    {
        List<Filter> filterList = new ArrayList<Filter>();
        filterList.add(new LargerX2("Larger x2"));
        filterList.add(new SmallerX2("Smaller x2"));
        return filterList;
    }

    /**
     * Create and return a list of the colour reduction filters
     * @return The list of filters
     */

    private List<Filter> createColourReductionFilters()
    {
        List<Filter> filterList = new ArrayList<Filter>();
        filterList.add(new GreyScale("Greyscale"));
        return filterList;
    }

    /**
     * Create and return a list of the contrast filters
     * @return The list of filters
     */

    private List<Filter> createContrastFilters()
    {
        List<Filter> filterList = new ArrayList<Filter>();
        filterList.add(new Lighter("Lighter"));
        filterList.add(new Darker("Darker"));
        filterList.add(new EqualizeMono("Histogram equalize mono image"));
        filterList.add(new EqualizeColour("Histogram equalize colour image"));
        filterList.add(new Invert("Invert"));
        return filterList;
    }

    // Build GUI -------------------------------------------------------

    /**
     * Create the Swing frame and its content
     */

    private void makeFrame()
    {
        frame = new JFrame("PhotoBench");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container contentPane = frame.getContentPane();
        makeMenuBar(frame);

        // Specify the layout manager with nice spacing

        contentPane.setLayout(new BorderLayout(6, 6));
        filenameLabel = new JLabel();
        contentPane.add(filenameLabel, BorderLayout.NORTH);
        imagePanel = new ImagePanel();
        contentPane.add(imagePanel, BorderLayout.CENTER);
        statusLabel = new JLabel(VERSION);
        contentPane.add(statusLabel, BorderLayout.SOUTH);

        // building is done - arrange the components and show

        showFilename(null);
        frame.pack();

        // center the frame on screen

        Dimension d = Toolkit.getDefaultToolkit().getScreenSize();
        frame.setLocation(d.width/2 - frame.getWidth()/2, d.height/2 - frame.getHeight()/2);
        frame.setVisible(true);
    }

    /**
     * Create the main frame's menu bar
     * @param frame The frame that the menu bar should be added to
     */

    private void makeMenuBar(JFrame frame)
    {
        JMenuBar menubar = new JMenuBar();
        frame.setJMenuBar(menubar);
        JMenu menu;
        JMenuItem item;

        // create the File menu

        menu = new JMenu("File");
        menubar.add(menu);

        item = new JMenuItem("Open");
        item.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) { openFile(); }
        });
        menu.add(item);

        item = new JMenuItem("Close");
        item.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) { close(); }
        });
        menu.add(item);
        menu.addSeparator();

        item = new JMenuItem("Save As...");
        item.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) { saveAs(); }
        });
        menu.add(item);
        menu.addSeparator();

        item = new JMenuItem("Quit");
        item.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) { quit(); }
        });
        menu.add(item);

        // create the resize menu

        menu = new JMenu("Resize");
        menubar.add(menu);
        for (final Filter filter : resizeFilters) {
            item = new JMenuItem(filter.getName());
            item.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) { applyFilter(filter); }
            });
            menu.add(item);
         }

        // create the colour reduction menu

        menu = new JMenu("Colour reduction");
        menubar.add(menu);
        for (final Filter filter : colourReductionFilters) {
            item = new JMenuItem(filter.getName());
            item.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) { applyFilter(filter); }
            });
            menu.add(item);
         }

        // create the contrast menu

        menu = new JMenu("Contrast");
        menubar.add(menu);
        for (final Filter filter : contrastFilters) {
            item = new JMenuItem(filter.getName());
            item.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) { applyFilter(filter); }
            });
            menu.add(item);
         }

        // create the Help menu

        menu = new JMenu("Help");
        menubar.add(menu);
        item = new JMenuItem("About PhotoBench...");
        item.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) { showAbout(); }
        });
        menu.add(item);

    }

    // Command line interface ------------------------------------------

    /**
     * Main method used when the program is executed from a command line.<br>
     * <b>DON'T USE THIS METHOD UNDER BLUEJ.</b>
     * @param args the command line arguments
     */

    public static void main(String[] args)
    {
        PhotoBench bench = new PhotoBench();
    }

}

