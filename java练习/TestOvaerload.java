public class TestOverload {
	
	void max(int a, int b) {
		System.out.println(a > b ? a : b);
	}
	
	void max(short a, short b) {
		System.out.println(a > b ? a : b);
	}
	
	void max(float x, float y) {
		System.out.println(a > b ? a : b);
	}
	
	public static void main(String[] args) {
		TestOverload t = new TestOverload();
		t.max(3, 4);   //����int��3,4Ĭ��Ϊint��
		short a=3;
		short b=4;
		t.max(3, 4);
	}
}