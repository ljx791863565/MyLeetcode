public class Welcome
{
	public static void main(String []args)
	{
		String []greeting = new String[3];
		greeting[0] = "welcome";
		greeting[1] = "to";
		greeting[2] = "java";

		for (String s : greeting){
			System.out.print(s);
		}
		System.out.println();
		for (int i = 0; i < greeting[0].length(); i++){
			System.out.print("=");
		}
		System.out.println();
	}
}
