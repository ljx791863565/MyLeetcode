import java.util.*;
public class TestCalendar
{
	public static void main(String []args)
	{
		Calendar c = Calendar.getInstance();
		System.out.println(c.getTime());
		System.out.println(c.get(c.YEAR));
		System.out.println(c.get(c.MONTH));
		System.out.println(c.get(c.DATE));
		c.set(2003, 10, 23, 12, 23, 21);
		System.out.println(c.getTime());
		c.add(c.YEAR, -1);
		System.out.println(c.getTime());
		c.roll(c.MONTH, -8);
		System.out.println(c.getTime());
	}
}
