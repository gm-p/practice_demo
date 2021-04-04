import java.awt.*;
import java.awt.event.*;

/*public class TestActionEvent {
	public static void main(String[] args) {
		Frame f = new Frame("Action Event");
		Button b = new Button("Press me");
		Monitor m = new Monitor();
		b.addActionListener(m);
		f.add(b, BorderLayout.CENTER);
		f.pack();
		f.setVisible(true);
	}
}

class Monitor implements ActionListener {
    public void actionPerformed(ActionEvent e) {
    	System.out.println("A Button has benn pressed!");
    }

}*/

public class TestActionEvent {
	public static void main(String[] args) {
		Frame f = new Frame("Test");
		Button b1 = new Button("Start");
		Button b2 = new Button("Stop");
		Monitor2 m = new Monitor2();
		b1.addActionListener(m);
		b2.addActionListener(m);
		b2.setActionCommand("game over");
		f.add(b1, "North");   //BorderLayout.NORTH
		f.add(b2, "Center");  //BorderLayout.CENTER
		f.pack();
		f.setVisible(true);
	}
}

class Monitor2 implements ActionListener {
    public void actionPerformed(ActionEvent e) {
    	System.out.println("A Button has been pressed, the relative info is:\n" + e.getActionCommand());
    }
}