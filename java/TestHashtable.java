import java.util.*;

class A
{
	int count;
	public A(int count)
	{
		this.count = count;
	}
	public boolean equals(Object obj)
	{
		if (obj == this){
			return true;
		}
		if (obj != null && obj.getClass() == A.class){
			A a = (A)obj;
			if (this.count == a.count){
				return true;
			}
		}
		return false;
	}
	public int hashCode()
	{
		return this.count;
	}
}

class B
{
	public boolean equals(Object obj)
	{
		return true;
	}
}

public class TestHashtable
{
	public static void main(String []args)
	{
		Hashtable ht = new Hashtable();
		ht.put(new A(60000), "疯狂java讲义");
		ht.put(new A(50000), "C++ Pirtrm");
		ht.put(new A(40000), new B());

		System.out.println(ht);

		System.out.println(ht.containsValue("测试字符"));

		System.out.println(ht.containsKey(new A(50000)));

		ht.remove(new A(40000));
		for (Object key : ht.keySet()){
			System.out.print(key + "--->");
			System.out.print(ht.get(key) + "\n");
		}
	}
}






