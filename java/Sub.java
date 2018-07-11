public class Sub extends Base{
	private String name;
	public void test()
	{
		System.out.println("子类的方法， name length= " + name.length());
	}
	public static void main(String []args){
		Sub b = new Sub();
		b.test();
	}
}
