public class BubbleSortAndBinarySearch {
	public static void main(String[] args) {
		Date[] days = new Date[5];
		days[0] = new Date(2006, 5, 4);
		days[1] = new Date(2006, 7, 4);
		days[2] = new Date(2008, 5, 4);
		days[3] = new Date(2004, 5, 9);
		days[4] = new Date(2004, 5, 4);
		
		//bubbleSort(days);
		selectionSort(days);
		for(int i=0; i<days.length; i++)
			System.out.println(days[i]);
		System.out.println(binarySearch(days, new Date(2006, 7, 4)));
	}
	
	private static Date[] bubbleSort(Date[] d) {
		Date tmp;
		for(int i=0; i<d.length-1; i++)
			for(int j=d.length-1; j>i; j--) {
				if(d[j-1].compare(d[j]) > 0) {
					tmp = d[j-1];
					d[j-1] = d[j];
					d[j] = tmp;
				}
			}
		return d;
	}
	
	private static Date[] selectionSort(Date[] d) {
		int k;
		Date tmp;
		for(int i=0; i<d.length-1; i++) {
			k = i;
			for(int j=i+1; j<d.length; j++) 
				if(d[j].compare(d[k]) < 0) 
					k = j;
			if(k != i) {
				tmp = d[k];
				d[k] = d[i];
				d[i] = tmp;
			}
		}
		return d;
	}
	
	private static int binarySearch(Date[] d, Date a) {
		if(d.length == 0)
			return -1;
		int startPos = 0;
		int endPos = d.length - 1;
		int mid;
		while(startPos <= endPos) {
			mid = (startPos + endPos) / 2;
			if(d[mid].compare(a) == 0)
				return mid;
			else if(d[mid].compare(a) > 0)
				endPos = mid - 1;
			else
				startPos = mid + 1;
		}
		return -1;
	}
}

class Date {
	int year, month, day;
	
	Date(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
	
	public int compare(Date date) {
		return year > date.year ? 1
			   : year < date.year ? -1
			   : month > date.month ? 1
			   : month < date.month ? -1
			   : day > date.day ? 1
			   : day < date.day ? -1 : 0;
	}
	
	public String toString() {
		return "Year:Month:Day -- " + year + "-" + month + "-" + day;
	}
}