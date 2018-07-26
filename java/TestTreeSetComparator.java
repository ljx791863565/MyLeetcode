import java.util.*;

class M
{
	int age;
	public M(int age)
	{
		this.age = age;
	}
	public String toString()
	{
		return "M 对象(age: " + age + ")";
	}
}
public class TestTreeSetComparator
{
	public static void main(String []args)
	{
		TreeSet ts = new TreeSet(new Comparator()
		{
			public int compare(Object obj1, Object obj2)
			{
				M m1 = (M)obj1;
				M m2 = (M)obj2;
				if (m1.age > m2.age){
					return -1;
				}else if(m1.age < m2.age){
					return 1;
				}else {
					return 0;
				}
			}
		});
		ts.add(new M(5));
		ts.add(new M(-3));
		ts.add(new M(9));
		System.out.println(ts);
	}
}
