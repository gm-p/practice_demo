import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class EmailSpider {

	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\asus\\Desktop\\1.html"));
			String line = "";
			while((line = br.readLine()) != null) {
				parse(line);
			}
		} catch (FileNotFoundException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		} catch (IOException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
	}

	private static void parse(String line) {
		// TODO 自动生成的方法存根
		Pattern p = Pattern.compile("[\\w[.-]]+@[\\w[.-]]+\\.[\\w]+");
		Matcher m = p.matcher(line);
		while(m.find()) {
			System.out.println(m.group());
		}
	}

}
