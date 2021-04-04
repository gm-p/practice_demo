import java.io.*;

public class FileList {
	public static void main(String[] args) {
		File f = new File("D:/java/mydir1");
		System.out.println(f.getName());
		tree(f, 1);
	}
	
	public static void tree(File f, int level) {
		File[] childs = f.listFiles();
		String preStr = "";
		for(int i=0; i<level; i++)
			preStr += "    ";
		
		for(int i=0; i<childs.length; i++) {
			System.out.println(preStr + childs[i].getName());
			if(childs[i].isDirectory()) {
				tree(childs[i], level + 1);
			}
		}
	}
}


/*import java.io.File;

public class FileList {
	public static void main(String[] args) {
		String path = "D:/java/mydir1";
		System.out.println(new File(path).getName());
		listFile(path, 1);
	}
	
	public static void listFile(String file, int level) {
		File f = new File(file);
		File[] list = f.listFiles();
			
		for(int i=0; i<list.length; i++) {
			for(int j=0; j<level; j++)
				System.out.print("\t");
			System.out.println(list[i].getName());
			if(list[i].isDirectory()) {
				listFile(list[i].toString(), level + 1);
			} 
		}
	}
}*/