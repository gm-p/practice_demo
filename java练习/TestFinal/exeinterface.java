interface PetCare {
	public void eat();
	public void play();
}

class Worker implements PetCare {
	public void eat() {
		System.out.println("����ιʳ����");
	}
	
	public void play() {
		System.out.println("���˺ͳ�����");
	}
}

class Farmer implements PetCare {
	public void eat() {
		System.out.println("ũ��ιʳ����");
	}
	public void play() {
		System.out.println("ũ��ͳ�����");
	}
	
}

class Cadre implements PetCare {
	public void eat() {
		System.out.println("���Ҹɲ�ιʳ����");
	}
	public void play() {
		System.out.println("���Ҹɲ��ͳ�����");
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