public class TestThread2 {
	public static void main(String[] args) {
		/*Runner1 r = new Runner1();
		Thread t1 = new Thread(r);
		Thread t2 = new Thread(r);
		t1.start();
		t2.start();*/
		
		/*Runner2 r = new Runner2();
		Thread t = new Thread(r);
		t.start();*/
		
		/*Runner3 r = new Runner3();
		Thread t = new Thread(r);
		t.start();
		for(int i=0; i<100000; i++) {
			if(i%10000 == 0 & i>0) {
				System.out.println("in thread main i=" + i);
			}
		}
		System.out.println("Thread main is over");
		r.shutdown();*/
		
		/*Runner4 r = new Runner4();
		Thread t = new Thread(r);
		t.start();
		try {
			t.join();
		} catch(InterruptedException e) {
			
		}
		for(int i=0; i<100; i++) 
			System.out.println("Ö÷Ïß³Ì:" + i);*/
		
		Runner5 r = new Runner5();
		Thread t = new Thread(r);
		t.start();
		
		for(int i=0; i<30; i++)
			System.out.println("MainThread: " + i);
	}
}

class Runner1 implements Runnable {
	public void run() {
		for(int i=0; i<30; i++)
			System.out.println("No." + i);
	}
}

class Runner2 implements Runnable {
	public void run() {
		for(int i=0; i<30; i++) {
			if(i%10 ==0 && i!=0) {
				try {
					Thread.sleep(1000);
				} catch(InterruptedException e) {
				    ;
				}
			}
			System.out.println("No. " + i);
		}
	}
}

class Runner3 implements Runnable {
	private boolean flag = true;
	public void run() {
		int i = 0;
		while(flag) {
			System.out.println(" " + i++);
		}
	}
	
	public void shutdown() {
		flag = false;
	}
}

class Runner4 implements Runnable {
	public void run() {
		for(int i=0; i<100; i++) {
			System.out.println("SubThread : " + i);
		}
	}
}

class Runner5 extends Thread {
	public void run() {
		System.out.println(Thread.currentThread().isAlive());
		for(int i=0; i<30; i++)
			System.out.println("SubThread: " + i);
	}
}