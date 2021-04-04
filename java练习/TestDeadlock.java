public class TestDeadlock implements Runnable {
    static Object o1 = new Object(), o2 = new Object();
	public int flag = 1;
	
	public void run() {
		System.out.println("flag = " + flag);
		if(flag == 1) {
			synchronized(o1) {
				System.out.println("flag1:o1");
				try {
					Thread.sleep(500);
				} catch(InterruptedException e) {
					e.printStackTrace();
				}
				synchronized(o2) {
					System.out.println("flag1:o2");
				}
			}
		}
		if(flag == 2) {
			synchronized(o2) {
				System.out.println("flag2:o2");
				try {
					Thread.sleep(500);
				} catch(InterruptedException e) {
					e.printStackTrace();
				}
				synchronized(o1) {
					System.out.println("flag2:o1");
				}
			}
		}
	}
	
	public static void main(String[] args) {
		TestDeadlock td1 = new TestDeadlock();
		TestDeadlock td2 = new TestDeadlock();
		td1.flag = 1;
		td2.flag = 2;
		Thread t1 = new Thread(td1);
		Thread t2 = new Thread(td2);
		t1.start();
		t2.start();
	}
}