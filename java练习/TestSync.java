public class TestSync implements Runnable {
	Timer timer = new Timer();
	public static void main(String[] args) {
		TestSync test = new TestSync();
		Thread t1 = new Thread(test);
		Thread t2 = new Thread(test);
		t1.setName("t1");
		t2.setName("t2");
		t1.start();
		t2.start();
	}
	public void run() {
		timer.add(Thread.currentThread().getName());
	}
}

class Timer {
	public static int num = 0;
	public synchronized void add(String name) {
		//synchronized(this) {
			num++;
			try {
				Thread.sleep(1);
			} catch(InterruptedException e) {
			
			}
			System.out.println(name + ", 你是第" + num +"个使用timer的线程");
	
		//}
	}
}

/*public class TestSync implements Runnable {
	int b = 100;
	
	public synchronized void m1() throws Exception{
		b = 1000;
		Thread.sleep(5000);
		System.out.println("b = " + b);
	}
	
	public void m2() {
		System.out.println(b);
	}
	
	public void run() {
		try {
			m1();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) throws Exception {
		TestSync ts = new TestSync();
		Thread t = new Thread(ts);
		t.start();
		
		Thread.sleep(1000);
		ts.m2();
	}
}*/