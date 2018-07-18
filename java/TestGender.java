public class TestGender
{
	public static void main(String []args)
	{
		Gender g = Enum.valueOf(Gender.class, "FEMALE");
		System.out.println(g + "代表:" + g.getName());

		Gender m = Enum.valueOf(Gender.class, "MALE");
		System.out.println(m + "代表:" + m.getName());
	}
}
