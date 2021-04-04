import java.io.File;
import java.io.IOException;

public class TestFile {
	public static void main(String[] args) {
		String separator = File.separator;
		String directory = "mydir1" + separator + "mydir2";
		String filename = "myfile.txt";
		File f = new File(directory, filename);
		if(f.exists()) {
			System.out.println("文件名：" + f.getAbsolutePath());
			System.out.println("文件大小：" + f.length());
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