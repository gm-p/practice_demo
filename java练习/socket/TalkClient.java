import java.io.*;
import java.net.*;

public class TalkClient {
	public static void main(String[] args) {
		try {
			Socket socket = new Socket("127.0.0.1", 8888);
			BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			PrintWriter pw = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));
			BufferedReader br1 = new BufferedReader(new InputStreamReader(System.in));
			//String sin = br.readLine();
			String sout = br1.readLine(); //null;
			while(!sout.equals("bye")) {
				pw.println(sout);
				pw.flush();
				System.out.println("Client: " + sout);
				System.out.println("Server: " + br.readLine());
				sout = br1.readLine();
			}
			/*while(!sin.equals("bye")) {
				System.out.println("Server: " + sin);
				sout = br1.readLine();
				pw.println(sout);
				pw.flush();
				System.out.println("Client: " + sout);
				sin = br.readLine();
			}*/
			br1.close();
			br.close();
			pw.close();
			socket.close();
		} catch(IOException e) {
			e.printStackTrace();
		}
	}
}