package com.gm.dp.strategy;

public class Dog implements Comparable {

	private int food;	
	
	public Dog(int food) {
		super();
		this.food = food;
	}	
	
	public int getFood() {
		return food;
	}

	public void setFood(int food) {
		this.food = food;
	}

	@Override
	public int compareTo(Object o) {
		if(o instanceof Dog) {
			Dog d = (Dog)o;
			if(this.food > d.getFood())  return 1;
			else if(this.food < d.getFood())  return -1;
			else  return 0;
		}
		return -100;
	}

	public String toString() {
		return food+"";
	}
}
