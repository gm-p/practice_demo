import java.awt.Color;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;


public class TankClient extends Frame {

	public static final int GAME_WIDTH = 800;
	public static final int GAME_HEIGHT = 600;
	
	int x = 50, y = 50;
	Image offScreenImage = null;
	
	public void launchFrame() {
		this.setLocation(200, 100);
		this.setBackground(Color.GREEN);
		this.setSize(GAME_WIDTH, GAME_HEIGHT);
		this.setTitle("TankWar");
		this.addWindowListener(new WindowAdapter() {

			@Override
			public void windowClosing(WindowEvent e) {
				setVisible(false);
				System.exit(0);
			}
			
		});
		this.addKeyListener(new KeyMonitor());
		this.setVisible(true);
		this.setResizable(false);
		new Thread(new PaintThread()).start();
	}
	
	public void paint(Graphics g) {
		Color c = g.getColor();
		g.setColor(Color.RED);
		g.fillOval(x, y, 30, 30);
		g.setColor(c);
	}
	

	public void update(Graphics g) {
		if(offScreenImage == null) {
			offScreenImage = this.createImage(GAME_WIDTH, GAME_HEIGHT);
		}
		Graphics gOffScreen = offScreenImage.getGraphics();
		Color c = gOffScreen.getColor();
		gOffScreen.setColor(Color.GREEN);
		gOffScreen.fillRect(0, 0, GAME_WIDTH, GAME_HEIGHT);
		gOffScreen.setColor(c);
		paint(gOffScreen);
		g.drawImage(offScreenImage, 0, 0, null);
	}

	public static void main(String[] args) {
		
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
	
	class KeyMonitor extends KeyAdapter {

		public void keyPressed(KeyEvent e) {
			int key = e.getKeyCode();
			switch(key) {
			case KeyEvent.VK_LEFT:
				x -= 5;
				break;
			case KeyEvent.VK_UP:
				y -= 5;
				break;
			case KeyEvent.VK_RIGHT:
				x += 5;
				break;
			case KeyEvent.VK_DOWN:
				y += 5;
				break;
			}
		}
		
	}
}


