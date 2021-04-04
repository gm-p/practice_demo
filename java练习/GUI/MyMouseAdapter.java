import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.Iterator;

public class MyMouseAdapter {
	public static void main(String[] args) {
		new MyFrame("MouseAdapter");
	}
}

class MyFrame extends Frame {
	ArrayList<Point> points;
	MyFrame(String s) {
		super(s);
		points = new ArrayList<Point>();
		setLayout(null);
		this.setBounds(200, 200, 640, 480);
		setBackground(new Color(204, 204, 255));
		this.addMouseListener(new Monitor());
		setVisible(true);
	}
	
	public void addPoint(Point p) {
		points.add(p);
	}
	
	public void paint(Graphics g) {
		Color c = g.getColor();
		Iterator<Point> i = points.iterator();
		while(i.hasNext()) {
			Point p = i.next();
			g.setColor(Color.BLUE);
			g.fillOval(p.x, p.y, 10, 10);
		}
		g.setColor(c);
	}
}

class Monitor extends MouseAdapter {
	public void mousePressed(MouseEvent e) {
		MyFrame f = (MyFrame)e.getSource();
		f.addPoint(new Point(e.getX(), e.getY()));
		f.repaint();
	}
}