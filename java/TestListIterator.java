import java.util.*;
public class TestListIterator
{
	public static void main(String []args)
	{
		String []books = {
			"疯狂java讲义",
			"C++ Pirtem"
		};

		List bookList = new ArrayList();
		for (int i = 0; i < books.length; i++){
			bookList.add(books[i]);
		}

		System.out.println(bookList);
		ListIterator lit = bookList.listIterator();
		while (lit.hasNext()){
			System.out.println(lit.next());
			lit.add("---------分割线---------");
		}
		System.out.println("==============================");
		while (lit.hasPrevious()){
			System.out.println(lit.previous());
		}
	}
}
