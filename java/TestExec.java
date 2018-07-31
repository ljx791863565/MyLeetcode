public class TestExec
{
	public static void main(String []args) throws Exception
	{
		Runtime rt = Runtime.getRuntime();
		rt.exec("notepad.exe");
	}
}
