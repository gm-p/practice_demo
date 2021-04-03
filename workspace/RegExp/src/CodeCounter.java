import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;


public class CodeCounter {

	static long whiteLines = 0;
	static long commentLines = 0;
	static long normalLines = 0;
	
	public static void main(String[] args) {
		File f = new File("D:\\java");
		File[] codeFiles = f.listFiles();
		for(File child : codeFiles) {
			if(child.getName().matches(".*\\.java$")) {
				parse(child);
			}
		}
		
		System.out.println("whiteLines : " + whiteLines);
		System.out.println("commentLines : " + commentLines);
		System.out.println("normalLines : " + normalLines);
	}

	private static void parse(File f) {
		BufferedReader br = null;
		boolean comment = false;
		try {
			br = new BufferedReader(new FileReader(f));
			String line = "";
			while((line=br.readLine()) != null) {
				line = line.trim();
				if(line.matches("^[\\s&&[^\\n]]*$")) {
					whiteLines++;
				} else if(line.startsWith("/*") && !line.endsWith("*/")) {
					comment = true;
					commentLines++;
				} else if(line.startsWith("/*") && (line.endsWith("*/"))) {
					commentLines++;
				} else if(line.startsWith("//")) {
					commentLines++;
				} else if(comment == true) {
					commentLines++;
					if(line.endsWith("*/")) {
						comment = false;
					}
				} else {
					normalLines++;
				}
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			if(br != null) {
				try {
					br.close();
					br = null;
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		}
	}

}
