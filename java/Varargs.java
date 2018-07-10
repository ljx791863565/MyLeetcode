public class Varargs{
	//长度可变的形参 ...表示 一个方法中最多有一个长度可变的形参
	//原理是多个相同类型的形参以数组方式传递给方法
	public static void test(int a, String ... str){
		for (String s : str)
			System.out.println(s);

		System.out.println("a = " + a);
	}
	public static void main(String []args){
		test(3, "hello", "world");
	}
}
