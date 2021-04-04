import java.io.*;

public class FileReaderAndFileWriter {
	public static void main(String[] args) {
		FileReader fr = null;
		FileWriter fw = null;
		int b = 0;
		try {
			fr = new FileReader("d:/java/FileReaderAndFileWriter.java");
			fw = new FileWriter("c:/users/asus/desktop/fw.java");
			//fw = new FileWriter("c:/users/asus/desktop/fw.dat");
			while((b=fr.read()) != -1) {
				System.out.print((char)b);
				fw.write(b);
			}
			fr.close();
			fw.close();
			//for(int i=0; i<=50000; i++)
				//fw.write(i);
		} catch(FileNotFoundException e) {
			System.out.println("找不到指定的文件！");
			System.exit(-1);
		} catch(IOException e) {
			System.out.println("读取文件失败！");
			System.exit(-1);
		}
		System.out.println();
		System.out.println("文件复制成功！");
	}
}