package com.gm.dp.strategy;

public class DataSorter {

	/*public static void sort(int[] a) {
		int n = a.length;
		//ð������
		/*for(int i=0; i<n-1; i++) {
			for(int j=n-1; j>i; j--) {
				if(a[j] < a[j-1]) {
					int temp = a[j];
					a[j] = a[j-1];
					a[j-1] = temp;
				}
			}
		}*/
		
		//ѡ������
		/*for(int i=0; i<n-1; i++) {
			int k=i;
			for(int j=i+1; j<n; j++) {
				if(a[k] > a[j])
					k = j;
			}
			if(k != i) {
				int temp = a[k];
				a[k] = a[i];
				a[i] = temp;
			}
		}
	}*/
			
	
	/*public static void sort(Cat[] c) {
		int n = c.length;
		for(int i=0; i<n-1; i++) 
			for(int j=n-1; j>i; j--) {
				if(c[j].getHeight() < c[j-1].getHeight()) {
					swap(c, j, j-1);
				}
			}
	}
	
	private static void swap(Cat[] c, int x, int y) {
		Cat temp = c[x];
		c[x] = c[y];
		c[y] = temp;
	}*/
	
	public static void sort(Object[] o) {
		int n = o.length;
		for(int i=0; i<n-1; i++) {
			for(int j=n-1; j>i; j--) {
				Comparable o1 = (Comparable)o[j];
				Comparable o2 = (Comparable)o[j-1];
				if(o1.compareTo(o2) == -1) {
					swap(o, j, j-1);
				}
			}
		}
	}

	private static void swap(Object[] o, int x, int y) {
		Object temp = o[x];
		o[x] = o[y];
		o[y] = temp;
	}

	public static void p(int[] a) {
		for(int i=0; i<a.length; i++) {
			System.out.print(a[i] + " ");
		}
		System.out.println();
	}

	public static void p(Object[] o) {
		for(int i=0; i<o.length; i++) {
			System.out.print(o[i] + " ");
		}
		System.out.println();
	}

}
