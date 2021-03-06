
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Rectangle;
import java.awt.Toolkit;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class Missile {

	public static final int XSPEED = 10;
	public static final int YSPEED = 10;
	
	public static final int WIDTH = 10;
	public static final int HEIGHT = 10;
	
	private int x, y;
	private boolean live = true;
	private boolean good;
	

	Direction dir;
	
	private TankClient tc;
	
	private static Toolkit tk = Toolkit.getDefaultToolkit();
	private static Image[] missileImages = null;
	private static Map<String, Image>  imgs = new HashMap<String, Image>();
	
	static {
		missileImages = new Image[] {
				tk.getImage(Missile.class.getClassLoader().getResource("images/missileL.gif")),
				tk.getImage(Missile.class.getClassLoader().getResource("images/missileLU.gif")),
				tk.getImage(Missile.class.getClassLoader().getResource("images/MissileU.gif")),
				tk.getImage(Missile.class.getClassLoader().getResource("images/missileRU.gif")),
				tk.getImage(Missile.class.getClassLoader().getResource("images/missileR.gif")),
				tk.getImage(Missile.class.getClassLoader().getResource("images/missileRD.gif")),
				tk.getImage(Missile.class.getClassLoader().getResource("images/missileD.gif")),
				tk.getImage(Missile.class.getClassLoader().getResource("images/missileLD.gif"))
		};
		
		imgs.put("L", missileImages[0]);
		imgs.put("LU", missileImages[1]);
		imgs.put("U", missileImages[2]);
		imgs.put("RU", missileImages[3]);
		imgs.put("R", missileImages[4]);
		imgs.put("RD", missileImages[5]);
		imgs.put("D", missileImages[6]);
		imgs.put("LD", missileImages[7]);
	}
	
	public boolean isLive() {
		return live;
	}

	public Missile(int x, int y, Direction dir) {
		this.x = x;
		this.y = y;
		this.dir = dir;
	}
	
	public Missile(int x, int y, boolean good, Direction dir, TankClient tc) {
		this(x, y, dir);
		this.good = good;
		this.tc = tc;
	}
	
	public void draw(Graphics g) {
		if(!live) {
			tc.missiles.remove(this);
			return ;
		}
		/*Color c = g.getColor();
		if(good)
			g.setColor(Color.RED);
		else
			g.setColor(Color.BLACK);
		g.fillOval(x, y, WIDTH, HEIGHT);
		g.setColor(c);*/
		
		
		move(g);
	}

	private void move(Graphics g) {
		 switch(dir) {
		 case L:
			 g.drawImage(imgs.get("L"), x, y, null);
			 x -= XSPEED;
			 break;
		 case LU:
			 g.drawImage(imgs.get("LU"), x, y, null);
			 x -= XSPEED;
			 y -= YSPEED;
			 break;
		 case U:
			 g.drawImage(imgs.get("U"), x, y, null);
			 y -= YSPEED;
			 break;
		 case RU:
			 g.drawImage(imgs.get("RU"), x, y, null);
			 x += XSPEED;
			 y -= YSPEED;
			 break;
		 case R:
			 g.drawImage(imgs.get("R"), x, y, null);
			 x += XSPEED;
			 break;
		 case RD:
			 g.drawImage(imgs.get("RD"), x, y, null);
			 x += XSPEED;
			 y += YSPEED;
			 break;
		 case D:
			 g.drawImage(imgs.get("D"), x, y, null);
			 y += YSPEED;
			 break;
		 case LD:
			 g.drawImage(imgs.get("LD"), x, y, null);
			 x -= XSPEED;
			 y += YSPEED;
			 break;
		 }
		 if(x<0 || y<0 || x>TankClient.GAME_WIDTH || y>TankClient.GAME_HEIGHT) {
			 live = false;
			// tc.missiles.remove(this);
		 }
	}
	
	public Rectangle getRect() {
		return new Rectangle(x, y, WIDTH, HEIGHT);
	}
	
	public boolean hitTank(Tank t) {
		if(this.live && this.getRect().intersects(t.getRect()) && t.isLive() && this.good != t.isGood()) {
			if(t.isGood()) {
				t.setLife(t.getLife() - 20);
				if(t.getLife() <= 0)
					t.setLive(false);
			}
			else {
				t.setLive(false);
			}
			this.live = false;
			Explode e = new Explode(x, y, tc);
			tc.explodes.add(e);
			return true;
		}
		return false;
	}
	
	public boolean hitTanks(List<Tank> tanks) {
		for(int i=0; i<tanks.size(); i++)
			if(hitTank(tanks.get(i)))
				return true;
		return false;
	}
	
	public boolean hitWall(Wall w) {
		if(this.live && this.getRect().intersects(w.getRect())) {
			live = false;
			return true;
		}
		return false;
	}
}