import java.awt.*;
import java.awt.event.*;

public class TestWindowClose {
	public static void main(String[] args) {
		new MyFrame("WindowClose");
	}
}

class MyFrame extends Frame {
	MyFrame(String s) {
		super(s);
		this.setBackground(new Color(204, 204, 255));
		this.setBounds(300, 300, 400, 300);
		setLayout(null);
		
		/* 匿名内部类
		this.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				setVisible(false);
				System.exit(-1);
			}
		});*/
		
		this.addWindowListener(new Monitor());
		setVisible(true);
	}
	
	class Monitor extends WindowAdapter {
		public void windowClosing(WindowEvent e) {
			setVisible(false);
			System.exit(0);
		}
	}
}