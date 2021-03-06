package com.gm.dp.strategy;

public class Cat implements Comparable {

	private int height;
	private int weight;
	private Comparator comparator = new CatWeightComparator(); //new CatHeightComparator();
	
	public Comparator getComparator() {
		return comparator;
	}

	public void setComparator(Comparator comparator) {
		this.comparator = comparator;
	}

	public Cat(int height, int weight) {
		super();
		this.height = height;
		this.weight = weight;
	}

	public int getHeight() {
		return height;
	}

	public void setHeight(int height) {
		this.height = height;
	}

	public int getWeight() {
		return weight;
	}

	public void setWeight(int weight) {
		this.weight = weight;
	}
	
	public String toString() {
		return height + "|" + weight;
	}

	@Override
	public int compareTo(Object o) {
		/*if(o instanceof Cat) { 
			Cat c = (Cat)o;
			if(this.getHeight() > c.getHeight()) return 1;
			else if(this.getHeight() < c.getHeight()) return -1;
			else return 0;
		}
		return -100;*/  //严格应该抛异常
		
		return comparator.compare(this, o);  //new CatHeightComparator().compare(this, o);
	}
}
