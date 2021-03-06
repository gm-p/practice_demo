import java.awt.Button;
import java.awt.Color;
import java.awt.Dialog;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Label;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.ArrayList;
import java.util.List;



public class TankClient extends Frame{
	public static final int GAME_WIDTH = 800;
	public static final int GAME_HEIGHT = 600;
	
	Tank myTank = new Tank(50, 50, true, Dir.STOP, this);
	List<Tank> tanks = new ArrayList<Tank>();
	List<Missile> missiles = new ArrayList<Missile>();
	
	List<Explode> explodes = new ArrayList<Explode>();
	
	Image offScreenImage = null;
	
	NetClient nc = new NetClient(this);
	
	ConnDialog dialog = new ConnDialog();
	
	@Override
	public void paint(Graphics g) {
		g.drawString("missiles count:" + missiles.size(), 10, 50);
		g.drawString("explodes count:" + explodes.size(), 10, 70);
		g.drawString("tanks count:" + tanks.size(), 10, 90);
		myTank.draw(g);		
		for(int i=0; i<missiles.size(); i++) {
			Missile m = missiles.get(i);
			//m.hitTanks(tanks);	
			if(m.hitTank(myTank)) {
				TankDeadMsg msg = new TankDeadMsg(this.myTank.id);
				nc.send(msg);
				MissileDeadMsg mdmMsg = new MissileDeadMsg(m.tankId, m.id);
				nc.send(mdmMsg);
			}
			m.draw(g);
			//if(!m.isLive()) 	missiles.remove(m);
			//else 	m.draw(g);
		}
		
		for(int i=0; i<explodes.size(); i++) {
			Explode e = explodes.get(i);
			e.draw(g);
		}
		
		for(int i=0; i<tanks.size(); i++) {
			Tank t = tanks.get(i);
			t.draw(g);
		}
	}

	@Override
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



	public  void launchFrame() {
		/*for(int i=0; i<10; i++) {
			tanks.add(new Tank(50 + 40*(i+1), 50, false, Dir.D, this));
		}*/
		
		setBounds(	200, 200, GAME_WIDTH, GAME_HEIGHT);  //setLocation(200, 200);  setSize(800, 600);
		setBackground(Color.GREEN);
		setTitle("TankWar");
		this.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
			
		});
		this.addKeyListener(new KeyMonitor());
		this.setResizable(false);
		setVisible(true);
		new Thread(new PaintThread()).start();
		
		//nc.connect("127.0.0.1", TankServer.TCP_PORT);
	}
	
	public static void main(String[] args) {
		TankClient tc = new TankClient();
		tc.launchFrame();
		
	}
	
	private class PaintThread implements Runnable {

		@Override
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
	
	private class KeyMonitor extends KeyAdapter {

		@Override
		public void keyReleased(KeyEvent e) {
			myTank.keyReleasedd(e);
		}

		@Override
		public void keyPressed(KeyEvent e) {
			int key = e.getKeyCode();
			if(key == KeyEvent.VK_C) {
				dialog.setVisible(true);
			} else {
				myTank.keyPressed(e);	
			}
		}
	}
		
	

	class ConnDialog extends Dialog {
		Button b = new Button("????");
		TextField tfIP = new TextField("127.0.0.1", 15);
		TextField tfPort = new TextField("" + TankServer.TCP_PORT, 4);
		TextField tfMyUdpPort = new TextField("2223", 4);
		public ConnDialog() {
			super(TankClient.this, true);
			this.setLayout(new FlowLayout());
			this.add(new Label("IP:"));
			this.add(tfIP);
			this.add(new Label("Port:"));
			this.add(tfPort);
			this.add(new Label("My UDP Port:"));
			this.add(tfMyUdpPort);
			this.add(b);
			this.setLocation(300, 300);
			this.pack();
			this.addWindowListener(new WindowAdapter() {

				@Override
				public void windowClosing(WindowEvent e) {
					setVisible(false);
				}
				
			});
			b.addActionListener(new ActionListener() {
				
				@Override
				public void actionPerformed(ActionEvent e) {
					String IP = tfIP.getText().trim();
					int port = Integer.parseInt(tfPort.getText().trim());
					int myUdpPort = Integer.parseInt(tfMyUdpPort.getText().trim());
					nc.setUdpPort(myUdpPort);
					nc.connect(IP, port);
					setVisible(false);
				}
			});
		}
	}

}
