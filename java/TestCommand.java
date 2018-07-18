public class TestCommand
{
	public static void main(String []args)
	{
		ProcessArray ps = new ProcessArray();
		int []target = {3, 4, 5, 6};
		ps.process(target, new PrintCommand());
		System.out.println("-----------------");
		ps.process(target, new AddCommand());
	}
}
