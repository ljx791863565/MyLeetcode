public class Parse{
	public static void main(String []args){
		//基本类型变量和字符串之间的转换
		String intStr = "123";
		int it = Integer.parseInt(intStr);
		System.out.println(it);

		String floatStr = "1.23";
		float ft = Float.parseFloat(floatStr);
		System.out.println(ft);

		String ftStr = String.valueOf(2.34f);
		System.out.println(ftStr);

		String dbStr = String.valueOf(3.45);
		System.out.println(dbStr);

		String boolStr = String.valueOf(true);
		System.out.println(boolStr.toUpperCase());
	}
}
