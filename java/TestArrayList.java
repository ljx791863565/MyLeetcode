import java.util.*;

public class TestArrayList
{
	public static void main(String []args)
	{
		List lt = Arrays.asList("疯狂java讲义", "C++Piretm");
		System.out.println(lt.getClass());
		for (int i = 0; i < lt.size(); i++){
			System.out.println(lt.get(i));
		}

	}
}
