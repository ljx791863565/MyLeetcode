public class CreateInnerInstance
{
	public static void main(String []args)
	{
		Out.In in = new Out().new In("测试信息");
		//Out.In in;
		//Out out = new Out();
		//in = out.new In("测试信息");
	}
}
