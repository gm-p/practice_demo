import java.awt.*;
import java.awt.event.*;

public class TFActionEvent {
	public static void main(String[] args) {
		new TFFrame();
	}
}

class TFFrame extends Frame {
	TFFrame() {
		TextField tf = new TextField();
		tf.addActionListener(new Monitor());
		tf.setEchoChar('*');
		add(tf, BorderLayout.CENTER);
		pack();
		setVisible(true);
	}
}

class Monitor implements ActionListener {
    public void actionPerformed(ActionEvent e) {
    	TextField tf = (TextField)e.getSource();
    	System.out.println(tf.getText());
    	tf.setText("");
    }
}