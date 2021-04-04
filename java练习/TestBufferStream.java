import java.io.*;

public class TestBufferStream {
	/*public static void main(String[] args) {
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter("c:/users/asus/desktop/dat.txt"));
			BufferedReader br = new BufferedReader(new FileReader("c:/users/asus/desktop/dat.txt"));
			String s = null;
			for(int i=0; i<100; i++) {
				s = String.valueOf(Math.random());
				bw.write(s);
				bw.newLine();
			}
			bw.flush();
			while((s=br.readLine()) != null) {
				System.out.println(s);
			}
			bw.close();
			br.close();
		} catch(IOException e) {
			e.printStackTrace();
		}
	}*/
	
	public static void main(String[] args) {
		try {
			FileInputStream fis = new FileInputStream("d:/java/TestBufferStream.java");
			BufferedInputStream bis = new BufferedInputStream(fis);
			System.out.println(bis.read());
			System.out.println(bis.read());
			bis.mark(100);
			int c = 0;
			for(int i=0; i<10 && (c=bis.read())!=-1; i++)
				System.out.print((char)c + " ");
			System.out.println();
			bis.reset();
			for(int i=0; i<10 && (c=bis.read())!=-1; i++)
				System.out.print((char)c + " ");
			System.out.println();
			bis.close();
		} catch(IOException e) {
			e.printStackTrace();
		}
	}
}