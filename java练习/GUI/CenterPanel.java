import java.awt.*;

public class CenterPanel {
	public static void main(String[] args) {
		MyFrame f = new MyFrame("FrameWithPanel", 200, 200, 400, 400, Color.BLUE);
	}
}

class MyFrame extends Frame {
	private Panel p;
	MyFrame(String s, int x, int y, int w, int h, Color color) {
		super(s);
		setLayout(null);
		setBounds(x, y, w, h);
		setBackground(color);
		p = new Panel();
		p.setBounds(w/4, h/4, w/2, h/2);
		p.setBackground(Color.YELLOW);
		add(p);
		setVisible(true);
	}
}