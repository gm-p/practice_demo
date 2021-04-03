import java.awt.BorderLayout;
import java.awt.Frame;
import java.awt.TextArea;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.net.SocketException;
import java.net.UnknownHostException;


public class ChatClient extends Frame {
	
	Socket s = null;
	DataOutputStream dos = null;
	DataInputStream dis = null;
	private boolean bConnected = false;
	
	TextField tfTxt = new TextField();
	TextArea taContent = new TextArea();
	
	Thread tRecv = new Thread(new RecvThread());
	
	public void launchFrame() {
		this.setLocation(400, 300);
		this.setSize(300, 300);
		this.setTitle("Chat");
		add(tfTxt, BorderLayout.SOUTH);
		add(taContent, BorderLayout.NORTH);
		pack();
		this.setVisible(true);
		addWindowListener(new WindowAdapter() {

			@Override
			public void windowClosing(WindowEvent e) {
				disconnect();
				System.exit(0);
			}
			
		});
		tfTxt.addActionListener(new TFListener()); 
		
		connect();
		
		tRecv.start();  //new Thread(new RecvThread()).start();
	}
	
	public void connect() {
		try {
			s = new Socket("127.0.0.1", 8888);
			dos = new DataOutputStream(s.getOutputStream());
			dis = new DataInputStream(s.getInputStream());
			bConnected = true;
System.out.println("connected!");
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
	
	public void disconnect() {
		/*try {
			bConnected = false;
			tRecv.join();	
		} catch (InterruptedException e) {
			e.printStackTrace();
		} finally {
			try {
				dos.close();
				dis.close();
				s.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
			
		}*/
		
		try {
			bConnected = false;
			dos.close();
			dis.close();
			s.close();
		} catch(IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		new ChatClient().launchFrame();
				
	}

	private class TFListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			String str = tfTxt.getText().trim();
			//taContent.setText(str);
			tfTxt.setText("");
			
			try {
				dos.writeUTF(str);
				dos.flush();
				//dos.close();
			} catch (IOException e1) {
				e1.printStackTrace();
			}
		}
		
	}

	private class RecvThread implements Runnable {

		@Override
		public void run() {
			try {
				while(bConnected) {
					String str = dis.readUTF();
					taContent.setText(taContent.getText() + str + '\n');
				}
			} catch(SocketException e) {
				System.out.println("ÍË³öÁË£¬bye£¡");
			} catch(IOException e) {
				e.printStackTrace();
			}
		}
		
	}
}
