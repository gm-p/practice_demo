package com.bjsxt.tank;
import java.awt.Color;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;

/**
 * ������������̹����Ϸ��������
 * @author asus
 *
 */

public class TankClient extends Frame {
	/**
	 * ����̹����Ϸ�Ŀ��
	 */
	public static final int GAME_WIDTH = 800;
	/**
	 * ����̹����Ϸ�ĸ߶�
	 */
	public static final int GAME_HEIGHT = 600;
	
	Tank myTank = new Tank(50, 50, true, Direction.STOP, this);
	
	Wall w1 = new Wall(100, 200, 20, 150, this), w2 = new Wall(300, 100, 300, 20, this);
	
	List<Tank> tanks = new ArrayList<Tank>();
	List<Explode> explodes = new ArrayList<Explode>();
	List<Missile> missiles = new ArrayList<Missile>();
	Image offScreenImage = null;
	
	Blood b = new Blood();
	
	/**
	 * ��������ʾ̹��������
	 */
	public void launchFrame() {
		
		/*Properties props = new Properties();
		 try {
			props.load(this.getClass().getClassLoader().getResourceAsStream("config/tank.properties"));
		} catch (IOException e1) {
			e1.printStackTrace();
		}*/
		
		int initTankCount = Integer.parseInt(PropertyMgr.getProperty("initTankCount"));  //Integer.parseInt(props.getProperty("initTankCount"));
		for(int i=0; i<initTankCount; i++) {
			tanks.add(new Tank(50 + 40*(i+1), 50, false, Direction.D, this));
		}
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
		/*
		 * ָ���ӵ�-��ը=̹�˵�����
		 * �Լ�̹�˵�����ֵ
		 */
		myTank.draw(g);
		g.drawString("missiles count: "+missiles.size(), 10, 50);
		g.drawString("explodes count: "+explodes.size(), 10, 70);
		g.drawString("tanks    count: "+tanks.size(), 10, 90);
		g.drawString("tank     life: "+myTank.getLife(), 10, 110);
		
		if(tanks.size() <= 0) {
			for(int i=0; i<Integer.parseInt(PropertyMgr.getProperty("reProduceTankCount")); i++) {
				tanks.add(new Tank(50 + 40*(i+1), 50, false, Direction.D, this));
			}
		}
		for(int i=0; i<missiles.size(); i++) {
			Missile m = missiles.get(i);
			/*if(!m.isLive()) 
				missiles.remove(m);
			else
				m.draw(g);*/
			m.hitTanks(tanks);
			m.hitTank(myTank);
			m.hitWall(w1);
			m.hitWall(w2);
			m.draw(g);
		}
		for(int i=0; i<explodes.size(); i++) {
			Explode e = explodes.get(i);
			e.draw(g);
		}
		for(int i=0; i<tanks.size(); i++) {
			Tank t = tanks.get(i);
			t.collidesWithwall(w1);
			t.collidesWithwall(w2);
			t.collidesWithTanks(tanks);
			t.draw(g);
		}
		w1.draw(g);
		w2.draw(g);
		b.draw(g);
		myTank.eat(b);
	}
	

	public void update(Graphics g) {
		if(offScreenImage == null) {
			offScreenImage = this.createImage(GAME_WIDTH, GAME_HEIGHT);
		}
		Graphics gOffScreen = offScreenImage.getGraphics();
		Color c = gOffScreen.getColor();
		gOffScreen.setColor(Color.BLACK);
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
			myTank.keyPressed(e);
		}

		@Override
		public void keyReleased(KeyEvent e) {
			myTank.keyReleased(e);
		}
		
		
		
	}
}


