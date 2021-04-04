public class TestSearch {
	public static void main(String[] args) {
		int[] a = {1, 3, 6, 8, 9, 10, 12, 18, 20, 34};
		System.out.println(binarySearch(a, 12));
	}
	
	private static int binarySearch(int[] a, int num) {
		if(a.length == 0)
			return -1;
		int startPos = 0;
		int endPos = a.length - 1;
		int mid; 
		while(startPos <= endPos) {
			mid= (startPos + endPos) / 2;
			if(a[mid] == num) {
				return mid;
			} else if(a[mid] > num) {
				endPos = mid - 1;
			} else {
				startPos = mid + 1;
			}
		}
		return -1;
	}
}