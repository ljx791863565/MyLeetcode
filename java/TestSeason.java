public class TestSeason
{
	public TestSeason(Season s)
	{
		System.out.println(s.getName() + "这真是一个 " + s.getDesc() + "季节");
	}
	public static void main(String []args)
	{
		new TestSeason(Season.getSeason(1));
	}
}
