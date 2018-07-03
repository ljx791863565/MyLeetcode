/**
 *Description
 *<br/>Copyright (C) , 2018-7-3 JiaXing Liao
 *<br/>This Program is protected by Copyright lows
 *<br/>Data:
 *<br/>Program Name:
 *@author JiaXing Liao liaojia138797@163.com 
 *@version
 */

public class JavaDoc{
	/**
	*简单测试属性
	**/
	protected String name;
	/**
	*主方法，程序入口
	**/
	public static void main(String [] args){
		System.out.println("hello world");
		int a = 6832;
		System.out.println(a);
		String str = "";
		for (int i=0; i<6; i++){
			a = (int)(Math.random() * 25 + 97);
			str += (char)a;
		}
		System.out.println(str);
		String s = "25";
		int value = Integer.parseInt(s);
		System.out.println(value);
		System.out.println("hello!" + 'a' + 7);
		System.out.println('a' + 7 + "hello!");
		long l1 = 787973193187983234L;
		long l2 = 437657362582598753L;
		System.out.println(l1);
		System.out.println(l2);
	}
}
