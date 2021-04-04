public class TestDataSort {
	public static void main(String[] args) {
		Date[] days = new Date[5];
		days[0] = new Date(2006, 5, 4);
		days[1] = new Date(2006, 7, 4);
		days[2] = new Date(2008, 5, 4);
		days[3] = new Date(2004, 5, 9);
		days[4] = new Date(2004, 5, 4);
		
		//bubbleSort(days);
		selectionSort(days);
		
		for(Date d : days) {
			System.out.println(d);
		}
		/*for(int i=0; i<days.length; i++)
			System.out.println(days[i]);*/
	}
	
	public static Date[] bubbleSort(Date[] a) {
		for(int i=0; i<a.length-1; i++)
			for(int j=a.length-1; j>i; j--) {
				if(a[j-1].compare(a[j]) == 1) {
					Date tmp = a[j-1];
					a[j-1] = a[j];
					a[j] = tmp;
				}
			}
		return a;
	}
	
	public static Date[] selectionSort(Date[] a) {
		int k;
		Date tmp;
		for(int i=0; i<a.length-1; i++) {
			k=i;
			for(int j=i+1; j<a.length; j++)
				if(a[j].compare(a[k]) == -1)
					k = j;
			if(k != i) {
				tmp = a[k];
				a[k] = a[i];
				a[i] = tmp;
			}
		}
		return a;
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