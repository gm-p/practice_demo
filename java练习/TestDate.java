import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.Date;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.sql.Timestamp;

public class TestDate {
	public static void main(String[] args) throws Exception {
		Class.forName("com.mysql.jdbc.Driver").newInstance();
		Connection conn = Drivermanager.getConnection("jdbc:mysql://localhost/mydata?user=root&password=root")
		Statement stmt = conn.createStatement();
		ResultSet rs = stmt.executeQuery("select pdate from article");
		while(rs.next()) {
			//Date d = rs.getDate("pdate");
			Timestamp ts = ts.getTimestamp("pdate");
			SimpleDateFormat sdf = new SimpleDateFormat("yyyy年mm月dd日 HH:mm:ss");

			System.out.println(sdf.format(ts));
			Calendar c = Calendar.getInstance();
			c.setTime(d);
			System.out.println(c.get(Calendar.MONTH));
		}
		rs.close();
		stmt.close();
		conn.close();
	}
}