import java.awt.*;
import java.awt.event.*;

public class TestPaint {
	public static void main(String[] args) {
		new PaintFrame().launchFrame();
	}
}

class PaintFrame extends Frame {
	public void launchFrame() {
		setBounds(200, 200, 640, 480);
		setVisible(true);
	}
	
	public void paint(Graphics g) {
		Color c = g.getColor();
		g.setColor(Color.RED);
		g.fillOval(50, 50, 30, 30);
		g.setColor(Color.GREEN);
		g.fillRect(80, 80, 30, 30);
		g.setColor(Color.ORANGE);
		g.drawLine(65, 65, 95, 95);
		g.setColor(Color.PINK);
		g.drawLine(400, 400, 600, 400);
		g.setColor(c);
	}
}