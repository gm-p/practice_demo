import java.util.*;

public class TestArgsWorks {
	/*private static final Integer ONE = new Integer(1);
	
	public static void main(String[] args) {
		Map m = new HashMap();
		for(int i=0; i<args.length; i++) {
			Integer freq = (Integer)m.get(args[i]);
			m.put(args[i], (freq == null ? ONE : new Integer(freq.intValue() + 1)));
		}
		System.out.println(m.size() + " distinct words detected!");
		System.out.println(m);
	}*/
	
	//使用自动打包和解包
	/*private static final int ONE = 1;
	public static void main(String[] args) {
		Map m = new HashMap();
		for(int i=0; i<args.length; i++) {
			int freq = (Integer)m.get(args[i]) == null ? 0 : (Integer)m.get(args[i]);
			m.put(args[i], (freq == 0) ? ONE : freq + 1);
		}
		System.out.println(m.size() + " distinct words detected !");
		System.out.println(m);
	}*/
	
	public static void main(String[] args) {
		Map<String, Integer> m = new HashMap<String, Integer>();
		for(int i=0; i<args.length; i++) {
			/*int freq = m.get(args[i]) == null ? 0 : m.get(args[i]);
			m.put(args[i], freq == 0 ? 1 : freq+1);*/
			if(!m.containsKey(args[i])) {
				m.put(args[i], 1);
			}  else {
				int freq = m.get(args[i]);
				m.put(args[i], freq+1);
			}
		}
		System.out.println(m.size() + " distinct words detected!");
		System.out.println(m);
	}
}