import java.util.*;

public class LinkList {
	public static void main(String[] args) {
		List l1 = new LinkedList();
		for(int i=0; i<5; i++)
			l1.add("a" + i);
		System.out.println(l1);
		l1.add(3, "hello");
		System.out.println(l1);
		l1.set(4, "world");
		System.out.print(l1.get(2) + " ");
		System.out.println(l1.indexOf("a4"));
		System.out.println(l1);
		l1.remove(1);
		System.out.println(l1);
		
		List l2 = new LinkedList();
	    for(int i=0; i<10; i++)
	    	l2.add("a" + i);
	    System.out.println(l2);
	    Collections.shuffle(l2);   //Ëæ»úÅÅÁÐ
	    System.out.println(l2);
	    Collections.reverse(l2);   //ÄæÐò
	    System.out.println(l2);
	    Collections.sort(l2);      //ÅÅÐò
	    System.out.println(l2);
	    System.out.println(Collections.binarySearch(l2, "a5"));  //ÕÛ°ë²éÕÒ
	}
}