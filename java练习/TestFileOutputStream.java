import java.io.*;

public class TestFileOutputStream {
	public static void main(String[] args) {
		int b = 0;
		FileInputStream in = null;
		FileOutputStream out = null;
		try {
			in = new FileInputStream("d:/java/TestFileOutputStream.java");
			out = new FileOutputStream("c:/users/asus/desktop/output.java");
			while((b=in.read()) != -1) {
				out.write(b);
			}
			in.close();
			out.close();
		} catch(FileNotFoundException e) {
			System.out.println("�Ҳ���ָ���ļ�!");
			System.exit(-1);
		} catch(IOException e) {
			System.out.println("�ļ����Ƴ���");
			System.exit(-1);
		}
		System.out.println("�ļ��Ѹ���");
	}
}