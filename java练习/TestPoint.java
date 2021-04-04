public class TestPoint {
	int x = 1;
	int y = 1;
	int z = 1;
	
	void setX(int _x) {
		x = _x;
	}
	
	void setY(int _y) {
		y = _y;
	}
	
	void setZ(int _z) {
		z = _z;
	}
	
    int distance() {
		return x * x + y * y + z * z;
	}
	
	public static void main(String[] args) {
		TestPoint p = new TestPoint();
		System.out.println("("+p.x+","+p.y+","+p.z+")");
		p.setX(2);
		System.out.println("("+p.x+","+p.y+","+p.z+")");
		p.setY(3);
		System.out.println("("+p.x+","+p.y+","+p.z+")");
		p.setZ(4);
		System.out.println("("+p.x+","+p.y+","+p.z+")");
		System.out.println("p点到原点的距平方为"+p.distance());
		
		Point p1 = new Point(1.0, 2.0, 3.0);
		Point p2 = new Point(0.0, 0.0, 0.0);
		System.out.println(p1.getdistance(p2));
		
		p1.setX(5.0);
		System.out.println(p1.getdistance(new Point(1.0, 1.0, 1.0)));
		
	}
	
}

class Point {
	double x, y, z;
	
	Point(double _x, double _y, double _z) {
		x = _x;
		y = _y;
		z = _z;
	}
	
	void setX(double _x) {
		x = _x;
	}
	
	void setY(double _y) {
		y = _y;
	}
	
	void setZ(double _z) {
		z = _z;
	}
	
	double getdistance(Point p) {
		return (x - p.x)*(x - p.x) + (y - p.y)*(y - p.y) + (z - p.z)*(z - p.z);
	}
}