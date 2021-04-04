import java.awt.*;

public class TestGridLayout {
	public static void main(String[] args) {
		Frame f = new Frame("GridLayout");
		f.setLayout(new GridLayout(3, 2));
		Button b1 = new Button("button1");
		Button b2 = new Button("button2");
		Button b3 = new Button("button3");
		Button b4 = new Button("button4");
		Button b5 = new Button("button5");
		Button b6 = new Button("button6");
		f.add(b1);
		f.add(b2);
		f.add(b3);
		f.add(b4);
		f.add(b5);
		f.add(b6);
		f.pack();
		f.setVisible(true);
	}
}