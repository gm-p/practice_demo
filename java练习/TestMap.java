import java.util.*;

public class TestMap {
	/*public static void main(String[] args) {
		Map m1 = new HashMap();
		Map m2 = new TreeMap();
		//m1.put("one", new Integer(1));
		m1.put("one", 1);
		//m1.put("two", new Integer(2));
		m1.put("two", 2);
		//m1.put("three", new Integer(3));
		m1.put("three", 3);
		//m2.put("A", new Integer(1));
		m2.put("A", 1);
		//m2.put("B", new Integer(2));
		m2.put("B", 2);
		System.out.println(m1.size());
		System.out.println(m1.containsKey("one"));
		//System.out.println(m1.containsValue(new Integer(3)));
		System.out.println(m1.containsValue(3));
		if(m1.containsKey("two")) {
			//int i = ((Integer)m1.get("two")).intValue();
			int i = (Integer)m1.get("two");
			System.out.println(i);
		}
		Map m3 = new HashMap(m1);
		m3.putAll(m2);
		System.out.println(m3);
	}*/
	
	
	//????ʵ??
	public static void main(String[] args) {
		Map<String, Integer> m1 = new HashMap<String, Integer>();
		Map<String, Integer> m2 = new TreeMap<String, Integer>();
		m1.put("one", 1);
		m1.put("two", 2);
		m1.put("three", 3);
		m2.put("A", 1);
		m2.put("B", 2);
		System.out.println(m1.size());
		System.out.println(m1.containsKey("one"));
		System.out.println(m1.containsValue(3));
		if(m1.containsKey("two")) {
			int i = m1.get("two");
			System.out.println(i);
		}
		
		Map<String, Integer> m3 = new HashMap<String, Integer>(m1);
		m3.putAll(m2);
		System.out.println(m3);
	}
}