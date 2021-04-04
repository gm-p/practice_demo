/*public class Count3Quit {
	public static void main(String[] args) {
		boolean[] arr = new boolean[500];
		for(int i=0; i<arr.length; i++)
			arr[i] = true;
		
		int leftCount = arr.length;
		int countNum = 0;
		int index = 0;
		
		while(leftCount > 1) {
			if(arr[index]) {
				countNum++;
				if(countNum == 3) {
					countNum = 0;
					arr[index] = false;
					leftCount--;
				}
			}
			index++;
			if(index == arr.length)
				index = 0;
		}
		
		for(int i=0; i<arr.length; i++)
			if(arr[i])
				System.out.println(i);
	}
}*/

public class Count3Quit {
	public static void main(String[] args) {
		KidCircle kc = new KidCircle(500);
		int countNum=0;
		Kid k = kc.first;
		while(kc.count > 1) {
			countNum++;
			if(countNum == 3) {
				kc.delete(k);
				countNum = 0;
			}
			k = k.right;
		}
		System.out.println(kc.first.id);
	}
}

class Kid {
	int id;
	Kid left;
	Kid right;
}

class KidCircle {
	int count = 0;
	Kid first;
	Kid last;
	
	KidCircle(int n) {
		for(int i=0; i<n; i++)
			add();
	}
	
	void add() {
		Kid k = new Kid();
		k.id = count;
		if(count <= 0) {
			first = k;
			last = k;
			k.left = k;
			k.right = k;
		}
		else {
			last.right = k;
			k.left = last;
			k.right = first;
			first.left = k;
			last = k;
		}
		count++;
	}
	
	void delete(Kid k) {
		if(count <= 0){
			return ;
		}
		else if(count == 1) {
			first = last = null;
		}
		else {
			k.left.right = k.right;
			k.right.left = k.left;
			
			if(k == last) {
				last = k.left;
			}
			else if(k == first) {
				first = k.right;
			}
		}
		count--;
	}
}