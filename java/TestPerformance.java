import java.util.*;

public class TestPerformance
{
	public static void main(String []args)
	{
		String []str = new String[900000];
		for (int i = 0; i < 900000; i++){
			str[i] = String.valueOf(i);
		}

		ArrayList al = new	ArrayList();
		for (int i = 0; i < 900000; i++){
			al.add(str[i]);
		}

		LinkedList ll = new LinkedList();
		for (int i = 0; i < 900000; i++){
			ll.add(str[i]);
		}

		long start = System.currentTimeMillis();
		for (Iterator it = al.iterator(); it.hasNext(); ){
			it.next();
		}
		System.out.println("迭代ArrayList集合元素的时间: " + (System.currentTimeMillis() - start));

		start = System.currentTimeMillis();
		for (Iterator it = ll.iterator(); it.hasNext(); ){
			it.next();
		}

		System.out.println("迭代LinkedList集合元素的时间: " + (System.currentTimeMillis() - start));
	}
}
