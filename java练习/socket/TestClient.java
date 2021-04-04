import java.net.*;
import java.io.*;

public class TestClient {
	public static void main(String[] args) {
		try {
			Socket s = new Socket("127.0.0.1", 8888);
			InputStream is = s.getInputStream();
			DataInputStream dis = new DataInputStream(is);
			System.out.println(dis.readUTF());
			dis.close();
			s.close();
		} catch(ConnectException coonE) {
			coonE.printStackTrace();
			System.out.println("服务器连接失败");
		} catch(IOException e) {
			e.printStackTrace();
		}
	}
}