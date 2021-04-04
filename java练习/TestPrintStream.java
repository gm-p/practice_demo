import java.io.*;
import java.util.*;

public class TestPrintStream {
	/*public static void main(String[] args) {
		PrintStream ps = null;
		try {
			FileOutputStream fos = new FileOutputStream("c:/users/asus/desktop/log.dat");
			ps = new PrintStream(fos);
		} catch(IOException e) {
			e.printStackTrace();
		}
		if(ps != null)
			System.setOut(ps);
		
		int ln = 0;
		for(char c=0; c<=60000; c++) {
			System.out.print(c);
			if(ln++ > 100) {
				System.out.println();
				ln = 0; 
			}
		}
	}*/
	
	/*public static void main(String[] args) {
		String filename = args[0];
		if(filename != null)
			list(filename, System.out);
	}
	
	public static void list(String f, PrintStream ps) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(f)); 
			String s = null;
			while((s=br.readLine()) != null) {
				ps.println(s);
			}
			br.close();
		} catch(IOException e) {
			ps.println("无法读取文件");
		}
	}*/
	
	public static void main(String[] args) {
		String s = null;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			FileWriter fw = new FileWriter("d:/java/logfile.log", true);
			PrintWriter log = new PrintWriter(fw);
			while((s=br.readLine()) != null) {
				if(s.equalsIgnoreCase("exit")) 
					break;
				System.out.println(s.toUpperCase());
				log.println("-----");
				log.println(s.toUpperCase());
				log.flush();
			}
			log.println("===" + new Date() + "===");
			log.flush();  //可以不写
			log.close();
		} catch(IOException e) {
			e.printStackTrace();
		}
	}
	
	
}