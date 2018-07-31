import java.util.*;
public class TestTimeZone
{
	public static void main(String []args)
	{
		String []time = TimeZone.getAvailableIDs();
		System.out.println(Arrays.toString(time));
		TimeZone my = TimeZone.getDefault();
		System.out.println("================================");
		System.out.println(my.getID());
		System.out.println(my.getDisplayName());
		System.out.println(TimeZone.getTimeZone("CNT").getDisplayName());
	}
}
