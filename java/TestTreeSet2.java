import java.util.*;
class R implements Comparable
{
	int count;
	public R(int count)
	{
		this.count = count;
	}
	public String toString()
	{
		return "R(count 属性: " + count + ")" ;
	}
	public boolean equals(Object obj)
	{
		if (obj instanceof R){
			R r = (R)obj;
			if (r.count == this.count){
				return true;
			}
		}
		return false;
	}
	public int compareTo(Object obj)
	{
		R r = (R)obj;
		if (this.count > r.count){
			return 1;
		}else if (this.count < r.count){
			return -1;
		}else{
			return 0;
		}
	}
}

public class TestTreeSet2
{
	public static void main(String []args)
	{
		TreeSet ts = new TreeSet();
		ts.add(new R(5));
		ts.add(new R(-3));
		ts.add(new R(9));
		ts.add(new R(-2));
		System.out.println(ts);

		R first = (R)ts.first();
		first.count = 20;
		R last = (R)ts.last();
		last.count = -2;
		System.out.println(ts);

		ts.remove(new R(-2));
		System.out.println(ts);

		ts.remove(new R(5));
		System.out.println(ts);
	}
}
