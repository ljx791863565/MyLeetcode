import java.util.*;
public class TestLinkedHashSet
{
	public static void main(String [] args)
	{	
		LinkedHashSet lt = new LinkedHashSet();
		lt.add(new String("疯狂java讲义"));
		lt.add(new String("java核心编程"));
		System.out.println(lt);

		lt.remove("疯狂java讲义");
		System.out.println(lt);

		lt.add(new String("疯狂java讲义"));
		System.out.println(lt);
	}
}
