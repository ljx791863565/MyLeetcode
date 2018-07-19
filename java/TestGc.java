public class TestGc
{
	private double height;
	public static void main(String []args)
	{
		for (int i = 0; i < 4; i++){
			new TestGc();
			System.gc();	
		//	RunTime.getRuntime().gc();
		}
	}
	public void finalize()
	{
		System.out.println("系统正在清理TestGc对象资源...");
	}
}
