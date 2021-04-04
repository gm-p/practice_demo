import java.awt.*;
import java.awt.event.*;

public class TestKey {
	public static void main(String[] args) {
		new KeyFrame().launchFrame();
	}
}

class KeyFrame extends Frame {
	TextField tf = null;
	
	public void launchFrame() {
		setSize(200, 200);
		setLocation(300, 300);
		tf = new TextField(10);
		tf.addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent e) {
				int keyCode = e.getKeyCode();
				if(keyCode == KeyEvent.VK_UP) {
					System.out.println("up arrow pressed");
				} else if(keyCode == KeyEvent.VK_DOWN) {
					System.out.println("down arrow pressed");
				}
			}
		});
		add(tf);
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				setVisible(false);
				System.exit(-1);
			}
		});
		//pack();
		setVisible(true);
		
	}
}