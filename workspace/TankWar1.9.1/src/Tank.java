import java.awt.Color;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.event.KeyEvent;
import java.util.Random;


public class Tank {
	int id;
	public static final int XSPEED = 5;
	public static final int YSPEED = 5;
	public static final int WIDTH = 30;
	public static final int HEIGHT = 30;
	
	int x, y;
	TankClient tc;
	
	private boolean bL=false, bU=false, bR=false, bD=false;
	//enum Dir {L, LU, U, RU, R, RD, D, LD, STOP};
	 Dir dir = Dir.STOP;
	Dir ptDir = Dir.D;
	
	boolean good;
	private boolean live = true;
	
	private static Random r = new Random();
	
	private int step = r.nextInt(12) + 3;
	
	public Tank(int x, int y, boolean good, Dir dir) {
		this.x = x;
		this.y = y;
		this.good = good;
		this.dir = dir;
	}
	
	public Tank(int x, int y, boolean good, Dir dir,TankClient tc) {
		this(x, y, good, dir);
		this.tc = tc;
	}

	public void draw(Graphics g) {
		if(!live) {
			if(!good) {
				tc.tanks.remove(this);
			}
			return ;
		}
		Color c = g.getColor();
		if(good)	g.setColor(Color.RED);
		else	g.setColor(Color.BLUE);
		g.fillOval(x, y, WIDTH, HEIGHT);
		g.drawString("id:" + id, x, y-10);
		g.setColor(c);
		
		move();
		
		switch(ptDir) {
		case L:
			g.drawLine(x + Tank.WIDTH/2, y + Tank.HEIGHT/2, x, y + Tank.HEIGHT/2);
			break;
		case LU:
			g.drawLine(x + Tank.WIDTH/2, y + Tank.HEIGHT/2, x, y);
			break;
		case U:
			g.drawLine(x + Tank.WIDTH/2, y + Tank.HEIGHT/2, x + Tank.WIDTH/2, y);
			break;
		case RU:
			g.drawLine(x + Tank.WIDTH/2, y + Tank.HEIGHT/2, x + Tank.WIDTH, y);
			break;
		case R:
			g.drawLine(x + Tank.WIDTH/2, y + Tank.HEIGHT/2, x + Tank.WIDTH, y + Tank.HEIGHT/2);
			break;
		case RD:
			g.drawLine(x + Tank.WIDTH/2, y + Tank.HEIGHT/2, x + Tank.WIDTH, y + Tank.HEIGHT);
			break;
		case D:
			g.drawLine(x + Tank.WIDTH/2, y + Tank.HEIGHT/2, x + Tank.WIDTH/2, y + Tank.HEIGHT);
			break;
		case LD:
			g.drawLine(x + Tank.WIDTH/2, y + Tank.HEIGHT/2, x, y + Tank.HEIGHT);
			break;
		}
	}
	
	void move() {
		switch(dir) {
		case L:
			x -= XSPEED;
			break;
		case LU:
			x -= XSPEED;
			y -= YSPEED;
			break;
		case U:
			y -= YSPEED;
			break;
		case RU:
			x += XSPEED;
			y -= YSPEED;
			break;
		case R:
			x += XSPEED;
			break;
		case RD:
			x += XSPEED;
			y += YSPEED;
			break;
		case D:
			y += YSPEED;
			break;
		case LD:
			x -= XSPEED;
			y += YSPEED;
			break;
		case STOP:
			break;
		}
		
		if(this.dir != Dir.STOP) {
			this.ptDir = this.dir;
		}
		
		if(x < 0)	x = 0;
		if(y < 25)	y = 25;
		if(x + Tank.WIDTH > TankClient.GAME_WIDTH)	x = TankClient.GAME_WIDTH - Tank.WIDTH;
		if(y + Tank.HEIGHT > TankClient.GAME_HEIGHT)	y = TankClient.GAME_HEIGHT - Tank.HEIGHT;
		
		/*if(!good) {
			Dir[] dirs = Dir.values();
			if(step == 0) {
				step = r.nextInt(12) + 3;
				int rn = r.nextInt(dirs.length);
				dir = dirs[rn];
			}
			step--;
			
			if(r.nextInt(40) > 38) 	this.fire();
		}*/
	}
	
	public void keyPressed(KeyEvent e) {
		int key = e.getKeyCode();
		switch(key) {
		case KeyEvent.VK_LEFT:
			bL = true;
			break;
		case KeyEvent.VK_UP:
			bU = true;
			break;
		case KeyEvent.VK_RIGHT:
			bR = true;
			break;
		case KeyEvent.VK_DOWN:
			bD = true;
			break;
		}
		locateDir();
	}
	
	
	void locateDir() {
		Dir oldDir = this.dir;
		
		if(bL && !bU && !bR && !bD)  dir = Dir.L;
		else if(bL && bU && !bR && !bD)  dir = Dir.LU;
		else if(!bL && bU && !bR && !bD)  dir = Dir.U;
		else if(!bL && bU && bR && !bD)  dir = Dir.RU;
		else if(!bL && !bU && bR && !bD)  dir = Dir.R;
		else if(!bL && !bU && bR && bD)  dir = Dir.RD;
		else if(!bL && !bU && !bR && bD)  dir = Dir.D;
		else if(bL && !bU && !bR && bD)  dir = Dir.LD;
		else if(!bL && !bU && !bR && !bD)  dir = Dir.STOP;
		
		if(dir != oldDir) {
			TankMoveMsg msg = new TankMoveMsg(id, x, y, dir, ptDir);
			tc.nc.send(msg);
		}
	}

	public void keyReleasedd(KeyEvent e) {
		int key = e.getKeyCode();
		switch(key) {
		case KeyEvent.VK_CONTROL:
			fire();   //tc.missiles.add(fire());
			break;
		case KeyEvent.VK_LEFT:
			bL = false;
			break;
		case KeyEvent.VK_UP:
			bU = false;
			break;
		case KeyEvent.VK_RIGHT:
			bR = false;
			break;
		case KeyEvent.VK_DOWN:
			bD = false;
			break;
		}
		locateDir();

	}
	
	private Missile fire() {
		if(!live)	return null;
		int x = this.x + Tank.WIDTH/2 - Missile.WIDTH/2;
		int y = this.y + Tank.HEIGHT/2 - Missile.HEIGHT/2;
		Missile m = new Missile(id, x, y, ptDir, good, this.tc);
		tc.missiles.add(m);
		
		MissileNewMsg msg = new MissileNewMsg(m);
		tc.nc.send(msg);
		return m;
	}
	
	public Rectangle getRect() {
		return new Rectangle(x, y, WIDTH, HEIGHT);
	}

	public boolean isLive() {
		return live;
	}

	public void setLive(boolean live) {
		this.live = live;
	}
	
	public boolean isGood() {
		return good;
	}



	
}
