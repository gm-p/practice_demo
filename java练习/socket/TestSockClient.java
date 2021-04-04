import java.io.*;
import java.net.*;

public class TestSockClient {
	public static void main(String[] args) {
		InputStream in = null;
		OutputStream out = null;
		try {
			Socket socket = /*new Socket("localhost", 8888);*/new Socket("127.0.0.1", 6666);
			in = socket.getInputStream();
			out = socket.getOutputStream();
			DataInputStream dis = new DataInputStream(in);
			DataOutputStream dos = new DataOutputStream(out);
			dos.writeUTF("Hello, server!");
			String s = null;
			if((s = dis.readUTF()) != null) {
				System.out.println(s);
			}
			dis.close();
			dos.close();
			socket.close();
		} catch(UnknownHostException e) {  //catch(ConnectException coonE) {
			e.printStackTrace();  //coonE.printStackTrace();
		} catch(IOException e) {
			e.printStackTrace();
		}
	}
}