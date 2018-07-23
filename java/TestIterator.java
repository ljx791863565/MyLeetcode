import java.util.HashSet;
import java.util.Collection;
import java.util.Iterator;
public class TestIterator
{
	public static void main(String []args)
	{
		Collection books = new HashSet();
		books.add("轻量级J2EE企业实用实战");
		books.add("疯狂java讲义");
		books.add("基于J2EE的Ajax指南");
		Iterator it = books.iterator();

		while (it.hasNext()){
			String book = (String)it.next();
			System.out.println(book);

			if (book.equals("疯狂java讲义")){
				it.remove();
			}
		}
		System.out.println(books);
	}
}
