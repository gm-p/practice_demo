public class dog {
	int furColor;
	float height;
	float weight;

	void catchMouse(Mouse m) {
		m.scream();
	}

	public static void main(String[] args) {
		dog d = new dog();
		Mouse m = new Mouse();
		d.catchMouse(m);
		
		Person tom = new Person(1, 25);
		Point = new Point();
	}
}

class Mouse {
	
}

class Person {
	int id;
	int age = 20;
	
	Person(int _id, int _age) {
		id = _id;
		age = _age;
	}
}

class Point {
	int x;
	int y;
}