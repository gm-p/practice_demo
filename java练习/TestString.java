public class TestString {
	public static void main(String[] args) {
		String s = "jaaaABBBBcc&^%adfsfdCCOOkk99876 _haHA";
		int upperNum=0, lowerNum=0, otherNum=0;
		
		/*for(int i=0; i<s.length(); i++) {
			char c = s.charAt(i);
			if('A' <= c && c <= 'Z')
				upperNum++;
			else if('a' <= c && c <= 'z')
				lowerNum++;
		}
		otherNum = s.length() - upperNum - lowerNum;*/
		
		/*String sU = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		String sL = "abcdefghijklmnopqrstuvwxyz";
		
		for(int i=0; i<s.length(); i++) {
			char c = s.charAt(i);
			if(sU.indexOf(c) != -1) {
				upperNum++;
			} else if(sL.indexOf(c) != -1) {
				lowerNum++;
			} else {
				otherNum++;
			}
		}*/
		
		for(int i=0; i<s.length(); i++) {
			char c = s.charAt(i);
			if(Character.isUpperCase(c)) {
				upperNum++;
			} else if(Character.isLowerCase(c)) {
				lowerNum++;
			} else {
				otherNum++;
			}
		}
		
		System.out.println("大写字母数为：" + upperNum);
	    System.out.println("小写字母数为：" + lowerNum);
	    System.out.println("非英文字母数为：" + otherNum);
	    
	    String s1 = "sunjavahpjavaokjavajavahahajavajavagoodjava";
	    int i=0, count=0;
	    String s2 = "java";
	    while((i=s1.indexOf(s2, i)) != -1) {
	    	count++;
	    	i++;
	    }
	    
	    /*int count = 0;
	    String sToFind = "java";
	    int index = -1;
	    while((index = s1.indexOf(sToFind)) != -1) {
	    	s1 = s1.substring(index + sToFind.length());
	    	count++;
	    }*/
	    
	    System.out.println(count);
	}
}