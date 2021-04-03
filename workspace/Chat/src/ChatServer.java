import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.EOFException;
import java.io.IOException;
import java.net.BindException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class ChatServer {

	boolean started = false;
	ServerSocket ss = null;
	
	List<Client> clients = new ArrayList<Client>();

	public void start() {
		// Socket s = null;
		try {
			ss = new ServerSocket(8888);
			started = true;
		} catch (BindException e) {
			System.out.println("端口使用中。。。");
			System.out.println("请停掉相关程序并重新运行服务器！");
			System.exit(0);
		} catch (IOException e) {
			e.printStackTrace();
		}

		try {
			while (started) {
				Socket s = ss.accept();
				Client c = new Client(s);
System.out.println("a client connected!");
				
				clients.add(c);
				new Thread(c).start();
				// dis.close();
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				ss.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

	}

	public static void main(String[] args) {
		new ChatServer().start();
	}

	class Client implements Runnable {

		private Socket s = null;
		private DataInputStream dis = null;
		private DataOutputStream dos = null;
		private boolean bConnected = false;

		public Client(Socket s) {
			this.s = s;
			try {
				dis = new DataInputStream(s.getInputStream());
				dos = new DataOutputStream(s.getOutputStream());
				bConnected = true;
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

		public void send(String str) {
			try {
				dos.writeUTF(str);
			} catch (IOException e) {
				//e.printStackTrace();
				clients.remove(this);
				System.out.println("对方退出了！我从List里面去掉了！");
			}
		}
		
		@Override
		public void run() {
			try {
				while (bConnected) {
					String str = dis.readUTF();
System.out.println(str);
					
					for(int i=0; i<clients.size(); i++) {
						Client c = clients.get(i);
						c.send(str);
					}
					
					/*for(Iterator<Client> it=clients.iterator(); it.hasNext(); ) {
						Client c = it.next();
						c.send(str);
					}*/
					
					/*Iterator<Client> it = clients.iterator();
					while(it.hasNext()) {
						Client c = it.next();
						c.send(str);
					}*/
					
				}
			} catch (EOFException e) {
				System.out.println("Client closed!");
			} catch (IOException e) {
				e.printStackTrace();
			} finally {
				try {
					if (dis != null)  dis.close();
					if (dos != null)  dos.close();
					if (s != null)	{
						s.close();
						s = null;
					}
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		}
	}

}
