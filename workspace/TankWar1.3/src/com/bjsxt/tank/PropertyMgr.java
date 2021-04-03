package com.bjsxt.tank;
import java.io.IOException;
import java.util.Properties;

/**
 * ����ģʽ���������ļ���Ӳ�̶����ڴ�
 * @author asus
 *
 */
public class PropertyMgr {
	static Properties props = new Properties();
	
	static {
		try {
			props.load(PropertyMgr.class.getClassLoader().getResourceAsStream("config/tank.properties"));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	private PropertyMgr() {}
	
	public static String getProperty(String key) {
		return props.getProperty(key);
	}
}
