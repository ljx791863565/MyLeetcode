import java.util.*;
public class TestSynchronized
{
	public static void main(String []args)
	{
		Collection c = Collections.synchronizedCollection(new ArrayList());
		List list =	Collections.synchronizedList(new ArrayList());
		Set s = Collections.synchronizedSet(new HashSet());
		Map m = Collections.synchronizedMap(new HashMap());
	}
}
