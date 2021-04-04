import java.io.File;
import java.io.IOException;

public class TestFile {
	public static void main(String[] args) {
		String separator = File.separator;
		String directory = "mydir1" + separator + "mydir2";
		String filename = "myfile.txt";
		File f = new File(directory, filename);
		if(f.exists()) {
			System.out.println("�ļ�����" + f.getAbsolutePath());
			System.out.println("�ļ���С��" + f.length());
		} else {
			f.getParentFile().mkdirs();
			try {
			f.createNewFile();
			} catch(IOException e) {
				e.printStackTrace();
			}
		}
	}
}