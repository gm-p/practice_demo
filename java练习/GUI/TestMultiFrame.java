import java.awt.*;

public class TestMultiFrame {
	public static void main(String[] args) {
		MyFrame frame1 = new MyFrame(100, 100, 200, 200, Color.RED);
		MyFrame frame2 = new MyFrame(300, 100, 200, 200, Color.GREEN);
		MyFrame frame3 = new MyFrame(100, 300, 200, 200, Color.YELLOW);
		MyFrame frame4 = new MyFrame(300, 300, 200, 200, Color.BLUE);
	}
}

class MyFrame extends Frame {
	static int id = 0;
	MyFrame(int x, int y, int w, int h, Color color) {
		super("MyFrame" + (++id));
		setBounds(x, y, w, h);
		setBackground(color);
		setLayout(null);
		setVisible(true);
	}
}