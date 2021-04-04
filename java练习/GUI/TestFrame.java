import java.awt.*;
public class TestFrame {
	public static void main(String[] args) {
		Frame f = new Frame("My first Frame");
		f.setLocation(300, 300);
		f.setSize(180, 100);
		f.setBackground(Color.blue);
		//f.setTitle("我的第一个敞口");
		f.setResizable(false);
		f.setVisible(true);
	}
}