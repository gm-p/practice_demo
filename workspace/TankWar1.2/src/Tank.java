import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Rectangle;
import java.awt.Toolkit;
import java.awt.event.KeyEvent;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;


public class Tank {
	
	public static final int XSPEED = 5;
	public static final int YSPEED = 5;
	
	public static final int WIDTH = 30;
	public static final int HEIGHT = 30;
		
	TankClient tc;
	
	private int x, y;
	private int oldx, oldy;
	private int life = 100;
	private BloodBar bb = new BloodBar();
	
	public int getLife() {
		return life;
	}

	public void setLife(int life) {
		this.life = life;
	}

	private boolean good;
	private static Random r = new Random();
	
	private boolean bL=false, bU=false, bR=false, bD=false;
    //enum Direction{L, LU, U, RU, R, RD, D, LD, STOP};
	private Direction dir = Direction.STOP;
	private Direction ptDir = Direction.D;
	
	private boolean live = true;
	private int step = r.nextInt(12) + 3;
	
	private static Toolkit tk = Toolkit.getDefaultToolkit();
	private static Image[] tankImages = null;
	private static Map<String, Image> imgs = new HashMap<String, Image>();
	
	static {
		tankImages = new Image[]{
			tk.getImage(Tank.class.getClassLoader().getResource("images/tankL.gif")),
			tk.getImage(Tank.class.getClassLoader().getResource("images/tankLU.gif")),
			tk.getImage(Tank.class.getClassLoader().getResource("images/tankU.gif")),
			tk.getImage(Tank.class.getClassLoader().getResource("images/tankRU.gif")),
			tk.getImage(Tank.class.getClassLoader().getResource("images/tankR.gif")),
			tk.getImage(Tank.class.getClassLoader().getResource("images/tankRD.gif")),
			tk.getImage(Tank.class.getClassLoader().getResource("images/tankD.gif")),
			tk.getImage(Tank.class.getClassLoader().getResource("images/tankLD.gif"))
		};
		
		imgs.put("L", tankImages[0]);
		imgs.put("LU", tankImages[1]);
		imgs.put("U", tankImages[2]);
		imgs.put("RU", tankImages[3]);
		imgs.put("R", tankImages[4]);
		imgs.put("RD", tankImages[5]);
		imgs.put("D", tankImages[6]);
		imgs.put("LD", tankImages[7]);
	}
	


	
	public Tank(int x, int y, boolean good) {
		this.x = x;
		this.y = y;
		this.oldx = x;
		this.oldy = y;
		this.good = good;
	}

	public Tank(int x, int y, boolean good, Direction dir, TankClient tc) {
		this(x, y, good);
		this.dir = dir;
		this.tc = tc;
	}
	
	private void stay() {
		x = oldx;
		y = oldy;
	}
	
	public void draw(Graphics g) {
		if(!live) {
			if(!good) {
				tc.tanks.remove(this);
			}
			return ;
		}
		/*Color c = g.getColor();
		if(good)
			g.setColor(Color.RED);
		else
			g.setColor(Color.BLUE);
		g.fillOval(x, y, WIDTH, HEIGHT);
		g.setColor(c);*/
		
		if(good)
			bb.draw(g);
		
		switch(ptDir) {
		case L:
			g.drawImage(imgs.get("L"), x, y, null);  //g.drawLine(x + WIDTH/2, y + HEIGHT/2, x, y + HEIGHT/2);
			break;
		case LU:
			g.drawImage(imgs.get("LU"), x, y, null);  //g.drawLine(x + WIDTH/2, y+HEIGHT/2, x, y);
			break;
		case U:
			g.drawImage(imgs.get("U"), x, y, null);  //g.drawLine(x + WIDTH/2, y + HEIGHT/2, x + WIDTH/2, y);
			break;
		case RU:
			g.drawImage(imgs.get("RU"), x, y, null);  //g.drawLine(x + WIDTH/2, y + HEIGHT/2, x + WIDTH, y);
			break;
		case R:
			g.drawImage(imgs.get("R"), x, y, null);  //g.drawLine(x + WIDTH/2, y + HEIGHT/2, x + WIDTH, y + HEIGHT/2);
			break;
		case RD:
			g.drawImage(imgs.get("RD"), x, y, null);  //g.drawLine(x + WIDTH/2, y + HEIGHT/2, x + WIDTH, y + HEIGHT);
			break;
		case D:
			g.drawImage(imgs.get("D"), x, y, null);  //g.drawLine(x + WIDTH/2, y + HEIGHT/2, x + WIDTH/2, y + HEIGHT);
			break;
		case LD:
			g.drawImage(imgs.get("LD"), x, y, null);  //g.drawLine(x + WIDTH/2, y + HEIGHT/2, x, y + HEIGHT);
			break;
		}
		move();
	}
	
	void move() {
		oldx = x;
		oldy = y;
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
		if(x < 0)
			x = 0;
		if(y < 30)
			y = 30;
		if(x + Tank.WIDTH > TankClient.GAME_WIDTH)
			x = TankClient.GAME_WIDTH - Tank.WIDTH;
		if(y + Tank.HEIGHT > TankClient.GAME_HEIGHT)
			y = TankClient.GAME_HEIGHT - Tank.HEIGHT;
		
		if(dir != Direction.STOP) {
			this.ptDir = dir;
		}
		
		if(!good) {
			Direction[] dirs = Direction.values(); 
			if(step == 0) {
				int rn = r.nextInt(dirs.length);
				dir = dirs[rn];
				step = r.nextInt(12) + 3;
			}
			step--;
			if(r.nextInt(40) > 38)
				this.fire();
		}
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
		case KeyEvent.VK_F2:
			if(!this.live) {
				this.live = true;
				this.life = 100;
			}
			break;
		}
		locateDirection();
	}
	
	void locateDirection() {
		if(bL && !bU && !bR && !bD)  dir = Direction.L;
		else if(bL && bU && !bR && !bD)  dir = Direction.LU;
		else if(!bL && bU && !bR && !bD)  dir = Direction.U;
		else if(!bL && bU && bR && !bD)   dir = Direction.RU;
		else if(!bL && !bU && bR && !bD)  dir = Direction.R;
		else if(!bL && !bU && bR && bD)   dir = Direction.RD;
		else if(!bL && !bU && !bR && bD)  dir = Direction.D;
		else if(bL && !bU && !bR && bD)   dir = Direction.LD;
		else if(!bL && !bU && !bR && !bD) dir = Direction.STOP;
	}

	public void keyReleased(KeyEvent e) {
		int key = e.getKeyCode();
		switch(key) {
		case KeyEvent.VK_CONTROL:
			fire();
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
		case KeyEvent.VK_A:
			this.superFire();
			break;
		}
		locateDirection();
	}
	
	public Missile fire() {
		if(!live)
			return null;
		int  x = this.x + Tank.WIDTH/2 - Missile.WIDTH/2;
		int  y = this.y + Tank.WIDTH/2 - Missile.WIDTH/2;
		Missile m = new Missile(x, y, good, ptDir, this.tc);
		tc.missiles.add(m);
		return m;
	}
	
	public Missile fire(Direction dir) {
		if(!live)
			return null;
		int x = this.x + Tank.WIDTH/2 - Missile.WIDTH /2;
		int y = this.y + Tank.HEIGHT/2 - Missile.HEIGHT /2;
		Missile m = new Missile(x, y, good, dir, this.tc);
		tc.missiles.add(m);
		return m;
	}

	public Rectangle getRect() {
		return new Rectangle(x, y, WIDTH, HEIGHT);  //(X,Y,tankImages[0].getWidth(null), tankImages[0].getHeight(null));
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
	
	public boolean collidesWithwall(Wall w) {
		if(this.live && this.getRect().intersects(w.getRect())) {
			this.stay();
			return true;
		}
		return false;
	}
	
	public boolean collidesWithTanks(List<Tank> tanks) {
		for(int i=0; i<tanks.size(); i++) {
			Tank t = tanks.get(i);
			if(this != t) {
				if(this.live && t.isLive() && t.getRect().intersects(this.getRect())) {
					this.stay();
					t.stay();
					return true;
				}
			}
		}
		return false;
	}
	
	public void superFire() {
		Direction[] dirs = Direction.values();
		for(int i=0; i<8; i++)
			fire(dirs[i]);
	}
	
	private class BloodBar {
		public void draw(Graphics g) {
			Color c = g.getColor();
			g.setColor(Color.RED);
			g.drawRect(x, y-10, WIDTH, 10);
			int w = WIDTH * life /100;
			g.fillRect(x, y-10, w, 10);
			g.setColor(c);
		}
	}
	
	public boolean eat(Blood b) {
		if(this.live && b.isLive() && this.getRect().intersects(b.getRect())) {
			this.setLife(100);
			b.setLive(false);
			return true;
		}
		return false;
	}
}
