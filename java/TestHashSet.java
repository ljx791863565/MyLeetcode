import java.util.HashSet;
class A
{
	public boolean equals(Object obj)
	{
		return true;
	}
}
class B
{
	public int hashCode()
	{
		return 1;
	}
}

class C
{
	//一版重写了equals后需要把hashCode也重写了
	//当equals返回两个对象为true时，hashCode返回的两个值也要相等
	public int hashCode()
	{
		return 2;
	}
	public boolean equals(Object obj)
	{
		return true;
	}
}

public class TestHashSet
{
	public static void main(String []args)
	{
		HashSet books = new HashSet();
		books.add(new A());
		books.add(new A());
		books.add(new B());
		books.add(new B());
		//C类重写了equals和hashCode函数。导致两次add会被HashSet认为是一个对象，所以只会add一次，第二次会失败
		books.add(new C());
		books.add(new C());

		System.out.println(books);
	}
}
