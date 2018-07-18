public class TestOutIn extends Out.In
{
	public TestOutIn(Out out)
	{
		out.super("hello");
	}
	public static void main(String []args)
	{
		Out out = new Out();
		TestOutIn ts = new TestOutIn(out);
	}
}
