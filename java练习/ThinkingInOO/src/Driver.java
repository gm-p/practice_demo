
public class Driver {
	private String name;
	
	
	public String getName() {
		return name;
	}


	public void setName(String name) {
		this.name = name;
	}


	public void drive(Vehicle v) {
		v.go(new Address("????"));
	}
	
	public void drive(Vehicle c, Address dest) {
		c.go(dest);
	}
}
