package com.bjsxt.dp.filter;

public class Main {
	public static void main(String[] args) {
		String msg = "��Һ�:), <script>, ���У� ����ҵ�� �����ڿ�û�о�����Ϊ��������һ��";
		MsgProcessor mp = new MsgProcessor();
		mp.setMsg(msg);
		String result = mp.process();
		System.out.println(result);
	}
}
