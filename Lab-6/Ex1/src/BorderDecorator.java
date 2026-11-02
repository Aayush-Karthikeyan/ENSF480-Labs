import java.awt.*;

public class BorderDecorator extends Decorator {
    public BorderDecorator(Component component, int x, int y, int width, int height) {
        super(component, x, y, width, height);
    }

    @Override
    public void draw(Graphics g){
        component.draw(g);
        // Create a graphics copy to protect the original state
        Graphics2D g2d = (Graphics2D) g.create();
        try{
            // Enable anti-aliasing for smooth edges
            g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

            // Define your dash pattern (dash length, gap length)
            float[] dashPattern = {6.0f, 6.0f};

            // Create the custom dashed stroke
            BasicStroke dashedStroke = new BasicStroke(
                    1.5f,                 // Line thickness
                    BasicStroke.CAP_BUTT,      // End cap style
                    BasicStroke.JOIN_MITER,    // Corner join style
                    10.0f,                     // Miter limit
                    dashPattern,               // The pattern array
                    0.0f                       // Dash phase offset
            );

            // Apply stroke, color, and draw the rectangle border
            g2d.setStroke(dashedStroke);
            g2d.setColor(Color.BLACK);
            g2d.drawRect(x, y, width, height);
        }finally {
            g2d.dispose();
        }
    }
}
