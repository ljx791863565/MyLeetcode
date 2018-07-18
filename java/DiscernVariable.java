public class DiscernVariable
{
	private String prop = "外部类属性";
	private class InClass
	{
		private String prop = "内部类属性";
		public void info()
		{
			String prop = "局部属性";
			System.out.println("外部类的属性值 : " + DiscernVariable.this.prop);
			System.out.println("内部类的属性值 : " + this.prop);
			System.out.println("局部属性值 : " + prop);
		}
	}
	public void test()
	{
		InClass is = new InClass();
		is.info();
	}
	public static void main(String []args)
	{
		DiscernVariable dv = new DiscernVariable();
		dv.test();
	}
}
