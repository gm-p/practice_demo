import java.awt.*;

public class TestMultiPanel {
	public static void main(String[] args) {
		MyFrame f = new MyFrame("My Frame with multi Panel", 200, 200, 400, 400);
	}
}

class MyFrame extends Frame {
	private Panel p1, p2, p3, p4;
	MyFrame(String s, int x, int y, int w, int h) {
		super(s);
		setLayout(null);
		setBounds(x, y, w, h);
		//setBackground(color);
		p1 = new Panel();
		p1.setBounds(0, 0, w/2, h/2);
		p1.setBackground(Color.RED);
		p2 = new Panel();
		p2.setBounds(w/2, 0, w/2, h/2);
		p2.setBackground(Color.GREEN);
		p3 = new Panel();
		p3.setBounds(0, h/2, w/2, h/2);
		p3.setBackground(Color.YELLOW);
		p4 = new Panel();
		p4.setBounds(w/2, h/2, w/2, h/2);
		p4.setBackground(Color.BLUE);
		add(p1);
		add(p2);
		add(p3);
		add(p4);
		setVisible(true);
	}
}