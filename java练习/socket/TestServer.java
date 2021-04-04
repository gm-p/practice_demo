import java.net.*;
import java.io.*;

public class TestServer {
	public static void main(String[] args) {
		try {
			ServerSocket ss = new ServerSocket(8888);
			while(true) {
				Socket s = ss.accept();
				OutputStream os = s.getOutputStream();
				DataOutputStream dos = new DataOutputStream(os);
				dos.writeUTF("Hello " + s.getInetAddress() + " port#" + s.getPort() + " bye-bye!");
				dos.close();
				s.close();
			}
		}  catch(IOException e) {
			e.printStackTrace();
			System.out.println("程序运行出错：" + e);
		}
	}
}