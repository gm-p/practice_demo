import java.awt.*;
import java.awt.event.*;

public class TestAnonymous {
	Frame f = new Frame("Java Frame");
	TextField tf = new TextField(10);
	Button b = new Button("Start");
	
	TestAnonymous() {
		f.add(tf, "North");
		f.add(b, "South");
		
		b.addActionListener(new ActionListener() {
			private int i;
			@Override
			public void actionPerformed(ActionEvent e) {

				System.out.println(e.getActionCommand() + (++i));
			}
		});
		
		f.addWindowListener(new WindowAdapter() {
			
			public void windowClosing(WindowEvent e) {
				f.setVisible(false);
				System.out.println(-1);
			}
		});
		
		f.pack();
		f.setVisible(true);
	}
	
	public static void main(String[] args) {
		new TestAnonymous();
	}
}