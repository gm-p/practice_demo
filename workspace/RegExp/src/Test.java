import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Test {
	 
	public static void main(String[] args) {
		// �򵥵���ʶ������ʽ�ĸ���
		/*p("abc".matches("..."));
		
		p("a8729a".replaceAll("\\d", "-"));
		
		Pattern p = Pattern.compile("[a-z]{3}");
		Matcher m = p.matcher("fgh");
		p(m.matches());
		p("fgha".matches("[a-z]{3}"));
		*/
		
		//������ʶ  . * + ?
		
	/*	p("a".matches("."));
		p("aa".matches("aa"));
		p("aaaa".matches("a*"));
		p("aaaa".matches("a+"));
		p("".matches("a*"));
		p("".matches("a?"));
		p("a".matches("a?"));
		p("aaaa".matches("a?"));
		p("214523145234532".matches("\\d{3,100}"));
		p("192.168.0.aaa".matches("\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}"));
		p("192".matches("[0-2][0-9][0-9]"));*/
		
		
		/*p("a".matches("[abc]"));
		p("a".matches("[^abc]"));
		p("A".matches("[a-zA-Z]"));
		p("A".matches("[a-z]|[A-Z]"));
		p("A".matches("[a-z[A-Z]]"));
		p("A".matches("[A-Z&&[RFG]]"));*/
		
		//��ʶ       \s  \w  \d   \
		/*p(" \n\r\t".matches("\\s{4}"));   // \s����հ��ַ�
		p(" ".matches("\\S"));  //������ȡ��������ǿհ��ַ�
		p("a_8".matches("\\w{3}"));  
		p("abc888&^%".matches("[a-z]{1,3}\\d+[&^#%]+"));
		p("\\".matches("\\\\"));*/
		
		//POSIX  Style
		//p("a".matches("\\p{Lower}"));
		
		
		
		//boundary
		/*p("hello sir".matches("^h.*"));
		p("hello sir".matches(".*ir$"));
		p("hello sir".matches("^h[a-z]{1,3}o\\b.*"));
		p("hellosir".matches("^h.[a-z]{1,3}o\\b.*"));*/
		
		//white lines
		/*p(" \n".matches("^[\\s&&[^\\n]]*\\n$"));  //��ͷ�ǿհ׷������ǻ��з�
		
		p("aaa 8888c".matches(".*\\d{4}."));
		p("aaa 8888c".matches(".*\\b\\d{4}."));
		p("aaa8888c".matches(".*\\d{4}."));
		p("aaa8888c".matches(".*\\b\\d{4}."));*/
		
		//matches ƥ�������ַ���    find ���Ӵ�     lookingAt ��ͷ��ʼ��
		/*Pattern p = Pattern.compile("\\d{3,5}");
		String s = "123-34345-234-00";
		Matcher m = p.matcher(s);
		p(m.matches());
		m.reset();
		p(m.find());  p(m.start() + "-" + m.end());
		p(m.find());  p(m.start() + "-" + m.end());
		p(m.find());  p(m.start() + "-" + m.end());
		p(m.find());
		
		p(m.lookingAt());
		p(m.lookingAt());
		p(m.lookingAt());
		p(m.lookingAt());*/
		
		//replacement
		//Pattern p = Pattern.compile("java", Pattern.CASE_INSENSITIVE);
		//Matcher m = p.matcher("java Java JAva JaVa IloveJAVA you hateJava afasdfasdaf");
		/*while(m.find()) {
			p(m.group());
		}*/
		//p(m.replaceAll("JAVA"));   //ȫ���滻Ϊ��д
		
		/*StringBuffer buf = new StringBuffer();
		int i=0;
		while(m.find()) {
			i++;
			if(i%2 == 0) {
				m.appendReplacement(buf, "java");  //ż���滻ΪСд
			} else {
				m.appendReplacement(buf, "JAVA");  //�����滻Ϊ��д
			}
		}
		m.appendTail(buf);
		p(buf);*/
		
		//group   С���ŷ���
		/*Pattern p = Pattern.compile("(\\d{3,5})([a-z]{2})");
		String s = "123aa-34345bb-234cc-00";
		Matcher m = p.matcher(s);
		while(m.find()) {
			p(m.group(1));
		}*/
		
		//quantifiers  x?̰��ȡ�����     x??ȡ���     x?+ȡ����£���Ч�ʸ�
		/*Pattern p = Pattern.compile("(.{3,10}+[0-9])");
		String s = "aaaa5bbbb68";
		Matcher m = p.matcher(s);
		if(m.find()) {
			p(m.start() + "-" + m.end());
		} else {
			p("not match");
		}*/
		
		//non-capturing groups
		/*Pattern p = Pattern.compile("(?!a).{3}");//(".{3}(?=a)");
		String s = "444a66b";
		Matcher m = p.matcher(s);
		while(m.find()) {
			p(m.group());
		} */
		
		//back references
		// \1�����һ�β������һ���ַ���
		Pattern p = Pattern.compile("(\\d(\\d))\\2");
		String s = "122";
		Matcher m = p.matcher(s);
		p(m.matches());
		
		//flags�ļ�д
		//Pattern p = Pattern.compile("java", Pattern.CASE_INSENSITIVE);
		p("Java".matches("(?i)(java)"));  //������һ��
		
		
	}
	
	public static void p(Object o) {
		System.out.println(o);
	}

}
