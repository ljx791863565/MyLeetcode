import java.util.*;

public class TestVector
{
	public static void main(String []args)
	{
		Stack s = new Stack();
		s.push("疯狂java讲义");
		s.push("C++Pirtem");
		s.push("算法导论");

		System.out.println(s);
		System.out.println(s.peek());
		s.pop();
		System.out.println(s.peek());
		System.out.println(s);
	}
}
