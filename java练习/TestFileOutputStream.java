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
			System.out.println("找不到指定文件!");
			System.exit(-1);
		} catch(IOException e) {
			System.out.println("文件复制出错！");
			System.exit(-1);
		}
		System.out.println("文件已复制");
	}
}