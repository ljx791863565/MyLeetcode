import java.util.*;
public class TestListErr
{
	public static void main(String []args)
	{
		List ls = new ArrayList();
		ls.add("疯狂java讲义");
		ls.add("C++Peimer");
//		ls.add(5);

		for (int i = 0; i < ls.size(); i++){
			String str = (String)ls.get(i);
		}
	}
}
