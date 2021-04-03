import java.awt.Color;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;


public class TankClient extends Frame {

	int x = 50, y = 50;
	Image offScreenImage = null;
	
	public void launchFrame() {
		this.setLocation(200, 100);
		this.setBackground(Color.GREEN);
		this.setSize(800, 600);
		this.setTitle("TankWar");
		this.addWindowListener(new WindowAdapter() {

			@Override
			public void windowClosing(WindowEvent e) {
				setVisible(false);
				System.exit(0);
			}
			
		});
		this.setVisible(true);
		this.setResizable(false);
		new Thread(new PaintThread()).start();
	}
	
	public void paint(Graphics g) {
		Color c = g.getColor();
		g.setColor(Color.RED);
		g.fillOval(x, y, 30, 30);
		g.setColor(c);
		y += 5;
	}
	

	public void update(Graphics g) {
		if(offScreenImage == null) {
			offScreenImage = this.createImage(800, 600);
		}
		Graphics gOffScreen = offScreenImage.getGraphics();
		Color c = gOffScreen.getColor();
		gOffScreen.setColor(Color.GREEN);
		gOffScreen.fillRect(0, 0, 800, 600);
		gOffScreen.setColor(c);
		paint(gOffScreen);
		g.drawImage(offScreenImage, 0, 0, null);
	}

	public static void main(String[] args) {
		
		/*
		 * Frame f = new Frame("TankWar");
		f.setBounds(200, 100, 800, 600);
		f.setVisible(true);
		f.addWindowListener(new WindowAdapter() {

			@Override
			public void windowClosing(WindowEvent e) {
				System.exit(-1);
			}
			
		});
		*/
		
		TankClient tc = new TankClient();
		tc.launchFrame();
	}

	private class PaintThread implements Runnable {
		public void run() {
			while(true) {
				repaint();
				try {
					Thread.sleep(50);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
		
	}
}


