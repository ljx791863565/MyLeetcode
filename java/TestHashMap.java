import java.util.*;

public class TestHashMap
{
	public static void main(String []args)
	{
		HashMap hm = new HashMap();
		hm.put(null, null);
		hm.put('a', null);
		hm.put(null, 'b');
		
		System.out.println(hm.toString());
		System.out.println(hm);
	}
}
