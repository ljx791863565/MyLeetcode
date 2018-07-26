import java.util.*;
public class TestList
{
	public static void main(String []args)
	{
		List books = new ArrayList();
		books.add(new String("疯狂java讲义"));
		books.add(new String("C++ Pirtem"));
		books.add(new String("算法导论"));
		System.out.println(books);

		books.add(1, new String("敏捷开发实践"));
		for (int i = 0; i < books.size(); i++){
			System.out.println(books.get(i));
		}

		books.remove(2);
		System.out.println(books);

		System.out.println(books.indexOf(new String("敏捷开发实践")));
		books.set(0, new String("C专家编程"));
		System.out.println(books);

		System.out.println(books.subList(1, 2));

	}
}
