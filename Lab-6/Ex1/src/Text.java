import java.awt.*;

public class Text implements Component {
    private int x;
    private int y;
    private String text;

    public Text(String text, int x, int y) {
        this.x = x;
        this.y = y;
        this.text = text;
    }

    @Override
    public void draw(Graphics g) {
        g.drawString(text, x, y);
    }
}
