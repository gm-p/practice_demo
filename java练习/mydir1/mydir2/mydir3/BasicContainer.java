import java.util.*;

public class BasicContainer {
	public static void main(String[] args) {
		Collection c = new ArrayList();
		c.add(new String("hello"));
		c.add(new Name("f1", "l1"));
		c.add(new Integer(100));
		c.remove(new String("hello"));
		c.remove(new Integer(100));
		System.out.println(c.remove(new Name("f1", "l1")));
		System.out.println(c.size());
		System.out.println(c);
		
		List l1 = new LinkedList();
		l1.add(new Name("Karl", "M"));
		l1.add(new Name("Steven", "Lee"));
		l1.add(new Name("John", "O"));
		l1.add(new Name("Tom", "M"));
		System.out.println(l1);
		Collections.sort(l1);
		System.out.println(l1);
	}
}

class Name implements Comparable {
	private String firstname, lastname;
	Name(String first, String last) {
		firstname = first;
		lastname = last;
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
	
	public int compareTo(Object o) {
		Name n = (Name)o;
		int lastCmp = lastname.compareTo(n.lastname);
		return (lastCmp != 0) ? lastCmp : firstname.compareTo(n.firstname); 
	}
}