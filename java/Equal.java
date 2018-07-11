public class Equal{
	public static void main(String []args){
		int it = 54;
		float ft = 54.0f;
		System.out.println("it == ft " + (it == ft));

		char ch = 'A';
		System.out.println("A == 65" + (ch == 65));

		String st1 = new String("hello");
		String st2 = new String("hello");
		System.out.println("str1 == str2" + (st1 == st2));
		System.out.println("str1 equal str2" + st1.equals(st2));

	}
}
