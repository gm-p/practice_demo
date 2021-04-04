import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;



public class TestReflection {
	public static void main(String[] args) throws ClassNotFoundException, InstantiationException, IllegalAccessException, InvocationTargetException{
		String str = "T";
		Class c = Class.forName(str);
		Object o = c.newInstance();
		Method[] methods = c.getMethods();
		for(Method m : methods) {
			if(m.getName().equals("mm")) {
				m.invoke(o);
			}
			if(m.getName().equals("m1")) {
				m.invoke(o, 1, 2);
				for(Class paramType : m.getParameterTypes()) {
					System.out.println(paramType.getName());
				}
			}
			if(m.getName().equals("getS")) {
				Class returnType = m.getReturnType();
				System.out.println(returnType.getName());
			}
			//System.out.println(m.getName());
		}
	}
}

class T {
	static {
		System.out.println("T loaded!");
	}
	
	public T() {
		System.out.println("T constructed!");
	}
	
	int i;
	String s;
	
	public void m1(int i, int j) {
		this.i = i + j;
		System.out.println(this.i);
	}
	
	public void mm() {
		System.out.println("m invoked");
	}
	
	public String getS() {
		return s;
	}
}