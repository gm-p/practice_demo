public class TestArray {
	public static void main(String[] args) {
		/*int[] a = {2, 4, 6, 7, 3, 5, 1, 9, 8};
		for(int i=0; i<a.length; i++)
			System.out.print(a[i] + " ");
		
		for(int i=0; i<args.length; i++)
			System.out.println(args[i]);*/
		if(args.length > 0) {
			int[] a = new int[args.length];
			for(int i=0; i<args.length; i++)
				a[i] = Integer.parseInt(args[i]);
			/*for(int i=1; i<args.length; i++)
				for(int j=args.length-1; j>=i; j--)
					if(a[j] < a[j-1]) {
						int tmp = a[j];
						a[j] = a[j-1];
						a[j-1] = tmp;
					}*/
			selectionSort(a);
			for(int i : a) 
				System.out.print(i + " ");
			
		}
		else {
			System.exit(-1);
		}
	}
	private static void selectionSort(int[] a) {
		int k, tmp;
		for(int i=0; i<a.length-1; i++) {
			k = i;
			for(int j=k+1; j<a.length; j++) {
				if(a[j] < a[k])
					k = j;
			}
			if(k != i) {
				tmp = a[k];
				a[k] = a[i];
				a[i] = tmp;
			}
		}
	}
}