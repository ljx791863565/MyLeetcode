import java.util.*;
class Z implements Comparable
{
	int age;
	public Z(int age)
	{
		this.age = age;
	}
	public boolean equals(Object obj)
	{
		return false;
	}
	public int compareTo(Object obj)
	{
		return 1;
	}
}
public class TestTreeSet
{
	public static void main(String []args)
	{
		TreeSet lt = new TreeSet();
/*
		lt.add(5);
		lt.add(2);
		lt.add(8);
		lt.add(4);

		System.out.println(lt);
		System.out.println("first : " + lt.first());
		System.out.println("last : " + lt.last());

		System.out.println("headSet : " + lt.headSet(4));
		System.out.println("tailSet : " + lt.tailSet(5));

		System.out.println("subSet : " + lt.subSet(-3, 5));
*/
		Z z1 = new Z(6);
		lt.add(z1);
		System.out.println(lt.add(z1));
		System.out.println(lt);
		((Z)(lt.first())).age = 9;
		System.out.println(((Z)(lt.last())).age);
	}
}
