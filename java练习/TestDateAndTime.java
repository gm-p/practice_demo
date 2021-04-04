import java.util.Date;
import java.util.Date;
import java.sql.Timestamp;
import java.util.GregorianCalendar;

public class TestDateAndTime {
	public static void main(String[] args) {
		//获取当前系统时间
		System.out.println(System.currentTimeMillis());
		Date d = new Date();
		Calendar c = Calendar.getInstance();

		String s = "1970-12-30 08:24:37.0";
		Timestamp ts = Timestamp.valueof(s);
		System.out.println(ts);

		Calendar cJapan = new GregorianCalendar(TimeZone.getTimeZone("Japan"));
		System.out.println(cJapan.get(Calendar.HOUR_OF_DAY));

		for(String str : TimeZone.getAvailableIDs()) {
			System.out.println(str);
		}
	}
}