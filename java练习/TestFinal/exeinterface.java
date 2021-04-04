interface PetCare {
	public void eat();
	public void play();
}

class Worker implements PetCare {
	public void eat() {
		System.out.println("工人喂食宠物");
	}
	
	public void play() {
		System.out.println("工人和宠物玩");
	}
}

class Farmer implements PetCare {
	public void eat() {
		System.out.println("农民喂食宠物");
	}
	public void play() {
		System.out.println("农民和宠物玩");
	}
	
}

class Cadre implements PetCare {
	public void eat() {
		System.out.println("国家干部喂食宠物");
	}
	public void play() {
		System.out.println("国家干部和宠物玩");
	}
}

public class exeinterface {
	public static void main(String[] args) {
		PetCare p = new Worker();
		p.eat();
		p.play();
		p = new Farmer();
		p.eat();
		p.play();
		p = new Cadre();
		p.eat();
		p.play();
	}
}