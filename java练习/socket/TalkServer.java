import java.io.*;
import java.net.*;

public class TalkServer {
	public static void main(String[] args) {
		try {
			ServerSocket ss = new ServerSocket(8888);
			Socket socket = ss.accept();
			BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			PrintWriter pw = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));
			//String sin = null;
			BufferedReader br1 = new BufferedReader(new InputStreamReader(System.in));
			String sout = br1.readLine();
			
			while(!sout.equals("bye")) {
				pw.println(sout);
				pw.flush();
				System.out.println("Server: " + sout);
				System.out.println("Client: " + br.readLine());
				sout = br1.readLine();
				//pw.write(sout);
				//sin = br.readLine();
			}
			
			br1.close();
			pw.close();
			br.close();
			socket.close();
			ss.close();
		} catch(IOException e) {
			e.printStackTrace();
		}
	}
}