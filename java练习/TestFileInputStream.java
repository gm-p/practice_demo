import java.io.*;

import javax.management.openmbean.InvalidOpenTypeException;

public class TestFileInputStream {
	public static void main(String[] args) {
		int b = 0;
		FileInputStream in = null;
		//FileReader in = null;
		try {
			in = new FileInputStream("D:/java/TestFileInputStream.java");
			//in = new FileReader("D:/java/TestFileInputStream.java");
		} catch(FileNotFoundException e) {
			System.out.println("�Ҳ���ָ���ļ���");
			System.exit(-1);
		}
		
		try {
			long num = 0;
			while((b=in.read()) != -1) {
				System.out.print((char)b);
				num++;
			}
			in.close();
			System.out.println();
			System.out.println("����ȡ�� " + num + "���ֽ�");
		} catch(IOException e) {
			System.out.println("�ļ���ȡ����");
			System.exit(-1);
		}
	}
}