
public class TestThread {
	public static void main(String[] args) {
		Runner1 r = new Runner1();
		r.start();
		//r.run();
		//Thread t = new Thread(r);
		//t.start();
		
		for(int i=1; i<=100; i++) {
			System.out.println("Main Thread ---- " + i);
		}
	}
}

//class Runner1 implements Runnable {
class Runner1 extends Thread {
	public void run() {
		for(int i=1; i<=100; i++) {
			System.out.println("Runner1 Thread ---- " + i);
		}
	}
}