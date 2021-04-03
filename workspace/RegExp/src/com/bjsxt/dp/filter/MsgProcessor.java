package com.bjsxt.dp.filter;

public class MsgProcessor {

	private String msg ;
	
	public String process() {
		//process the html tap <>
		String r = msg.replace("<", "[")
					.replace(">", "]");
		
		//process the sensitive words
		r = r.replace("被就业", "就业")
			 .replace("敏感", "");
		return r;
	}

	public String getMsg() {
		return msg;
	}

	public void setMsg(String msg) {
		this.msg = msg;
	}
	
	
}
