import java.awt.*;

public class TestFlowLayout {
	public static void main(String[] args) {
		/*Frame f = new Frame("FlowLayout");
		f.setLayout(new FlowLayout(FlowLayout.LEFT));
		Button button1 = new Button("open");
		Button button2 = new Button("close");
		Button button3 = new Button("save");
		f.add(button1);
		f.add(button2);
		f.add(button3);
		f.setBounds(200, 200, 100, 100);
		f.setVisible(true);*/
		
		
		Frame f = new Frame("Java Frame");
		FlowLayout l = new FlowLayout(FlowLayout.CENTER, 20, 40);
		f.setLayout(l);
		f.setLocation(300, 400);
		f.setSize(300, 200);
		f.setBackground(new Color(204, 204, 255));
		for(int i=0; i<7; i++)
			f.add(new Button("Button" + i));
		f.setVisible(true);
	}
}