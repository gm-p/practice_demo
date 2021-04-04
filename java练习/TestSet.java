/*import java.util.*;

public class TestSet {
	public static void main(String[] args) {
		Set s1 = new HashSet();
		s1.add("a");
		s1.add("b");
		s1.add("c");
		Set s2 = new HashSet();
		s2.add("d");
		s2.add("a");
		s2.add("b");
		Set sn = new HashSet(s1);
		sn.retainAll(s2);
		Set su = new HashSet(s1);
		su.addAll(s2);
		System.out.println(sn);
		System.out.println(su);
	}
}*/


import java.util.*;

public class TestSet {
	public static void main(String[] args) {
		Collection c = new HashSet();
		c.add(new Name("fff", "lll"));
		c.add(new Name("a", "b"));
		c.add(new Name("ccc", "ddd"));
		for(Iterator i=c.iterator(); i.hasNext(); ) {
			Name name = (Name)i.next();
			if(name.getFirstname().length() < 3) {
				i.remove();
			}
		}
		for(Object o : c)
			System.out.println(o);
		
		Set s = new HashSet();
		s.add("hello");
		s.add("world");
		s.add(new Name("f1", "l1"));
		s.add(new Integer(100));
		s.add("hello");
		s.add(new Name("f1", "l1"));
		System.out.println(s);
	}
}

class Name {
	private String firstname, lastname;
	
	Name(String firstname, String lastname) {
		this.firstname = firstname;
		this.lastname = lastname;
	}
	
	public String getFirstname() {
		return firstname;
	}
	
	public String getLastname() {
		return lastname;
	}
	
	public String toString() {
		return firstname + " " + lastname;
	}
	
	public boolean equals(Object obj) {
		if(obj instanceof Name) {
			Name name = (Name)obj;
			return name.firstname.equals(firstname) && name.lastname.equals(lastname);
		}
		return super.equals(obj);
	}
	
	public int hashCode() {
		return firstname.hashCode();
	}
}