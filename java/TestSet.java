import java.util.Set;
import java.util.HashSet;

public class TestSet
{
	public static void main(String []args)
	{
		Set books = new HashSet();
		books.add(new String("Struts2权威指南"));
		//set不允许有两个相同的元素
		boolean result = books.add(new String("Struts2权威指南"));
		System.out.println("result = " + result);

		books.add(new String("疯狂java讲义"));
		System.out.println(books);
	}
}
