import java.util.*;

public class TestSort
{
	public static void main(String []args)
	{
		ArrayList al = new ArrayList();
		al.add(5);
		al.add(-3);
		al.add(9);
		al.add(4);
		System.out.println(al);

		Collections.reverse(al);
		System.out.println(al);

		Collections.sort(al);
		System.out.println(al);

		Collections.shuffle(al);
		System.out.println(al);
	}
}
