import java.util.*;

public class BasicGeneric {
	public static void main(String[] args) {
		List<String> l1= new ArrayList<String>();
		l1.add("aaa");
		l1.add("bbb");
		l1.add("ccc");
		for(int i=0; i<l1.size(); i++) {
			String s = l1.get(i);
			System.out.println(l1.get(i));
		}
		
		Collection<String> c = new HashSet<String>();
		c.add("abc");
		c.add("bd");
		c.add("efg");
		for(Iterator<String> it=c.iterator(); it.hasNext(); ) {
			String s = it.next();
			System.out.println(s);
		}
	}
}

class MyName implements Comparable<MyName> {
	
	int age;
	
	public int compareTo(MyName mn) {
		if(this.age > mn.age) {
			return 1;
		} else if(this.age < mn.age) {
			return -1;
		} else {
			return 0;
		}
	}
}