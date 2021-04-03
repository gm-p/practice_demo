import java.awt.Color;
import java.awt.Font;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;


public class Yard extends Frame {
	
	PaintThread paintThread = new PaintThread();
	private boolean gameOver = false;
	
	public static final int ROWS = 30;
	public static final int COLS = 30;
	public static final int BLOCK_SIZE = 15;
	
	public static  int score = 0;
	
	Snake s = new Snake(this);
	
	Egg e = new Egg();
	
	Image offScreenImage = null;
	
	public void launch() {
		this.setLocation(200, 200);
		this.setSize(COLS*BLOCK_SIZE, COLS*BLOCK_SIZE);
		this.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				setVisible(false);
				System.exit(0);
		    }
			
		});
		setVisible(true);
		addKeyListener(new KeyMonitor());
		
		new Thread(paintThread).start();
		
	}
	
	public void stop() {
		gameOver = true;
	}
	
	@Override
	public void paint(Graphics g) {
		Color c = g.getColor();
		g.setColor(Color.GRAY);
		g.fillRect(0, 0, COLS*BLOCK_SIZE, ROWS*BLOCK_SIZE);
		g.setColor(Color.DARK_GRAY);
		//画出横线
		for(int i=1; i<ROWS; i++) {
			g.drawLine(0, i*BLOCK_SIZE, COLS*BLOCK_SIZE, i*BLOCK_SIZE);
		}
		for(int i=1; i<COLS; i++) {
			g.drawLine(i*BLOCK_SIZE, 0, i*BLOCK_SIZE, ROWS*BLOCK_SIZE);
		} 
		
		g.setColor(Color.YELLOW);
		g.drawString("score:"+score, 10, 60);
		
		if(gameOver == true) {
			g.setFont(new Font("华文彩云", Font.BOLD, 50));
			g.drawString("游戏结束", 120, 180);
			paintThread.pause();  //paintThread.gameOver();
		}
		
		g.setColor(c);
		
		s.eat(e);	
		s.draw(g);
		e.draw(g);
		
	}

	@Override
	public void update(Graphics g) {
		if(offScreenImage == null) {
			offScreenImage = this.createImage(COLS*BLOCK_SIZE, ROWS*BLOCK_SIZE);
		}
		Graphics gOff = offScreenImage.getGraphics();
		paint(gOff);
		g.drawImage(offScreenImage, 0, 0, null);
	}



	private class PaintThread implements Runnable {
		
		private boolean running = true;
		private boolean pause = false;
		public void run() {
			while(running) {
				if(pause)
					continue;
				else
					repaint();
				try {
					Thread.sleep(300);
				} catch(InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
		
		public void gameOver() {
			running = false;
		}
		
		public void pause() {
			pause = true;
		}
		
		public void reStart() {
			pause = false;
			s = new Snake(Yard.this);
			Yard.score = 0;
			gameOver = false;
		}
	}
	
	private class KeyMonitor extends KeyAdapter {

		@Override
		public void keyPressed(KeyEvent e) {
			int key = e.getKeyCode();
			if(key == KeyEvent.VK_F2)
				paintThread.reStart();
			
			s.keyPressed(e);
		}
		
	}
	
	public static void main(String[] args) {
		new Yard().launch();
	}

	public int getScore() {
		return this.score;
	}

	public void setSore(int s) {
		this.score = s;
	}

}
