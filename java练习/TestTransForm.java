import java.io.*;

public class TestTransForm {
	public static void main(String[] args) {
		try {
			OutputStreamWriter osw = new OutputStreamWriter(new FileOutputStream("c:/users/asus/desktop/char.txt"));
			osw.write("microsoftibmsunoracle");
			osw.close();
			System.out.println(osw.getEncoding());
			osw = new OutputStreamWriter(new FileOutputStream("c:/users/asus/desktop/char.txt", true), "ISO8859_1");  //latin-1
			osw.write("microsoftibmsunoracle");
			System.out.println(osw.getEncoding());
			osw.close();
		} catch(IOException e) {
			e.printStackTrace();
		}
		
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		String s = null;
		try {
			while((s=br.readLine()) != null) {
				if(s.equalsIgnoreCase("exit"))
					break;
				System.out.println(s.toUpperCase());
			}
			br.close();
			isr.close();
		} catch(IOException e) {
			e.printStackTrace();
		}
	}
}