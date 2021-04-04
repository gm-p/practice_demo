
public class Broom extends Vehicle{

	@Override
	public void go(Address dest) {
		System.out.println("一路扫着土去了"+dest.getName());
	}

}
