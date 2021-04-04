import java.util.*;

public class TestJoin {
	public static void main(String[] args) {
		MyThread t = new MyThread("t1");
		t.start();
		try {
		    t.join();	
		} catch(InterruptedException e) {
			
		}
		
		for(int i=0; i<10; i++) 
			System.out.println("I am main Thread");
	}
}

class MyThread extends Thread {
	MyThread(String s) {
		super(s);
	}
	
	public void run() {
		for(int i=0; i<10; i++) {
			System.out.println("I am " + getName());
		}
		try {
			sleep(1000);
		} catch(InterruptedException e) {
			return ;
		}
	}
}