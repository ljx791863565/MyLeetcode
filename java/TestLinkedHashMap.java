import java.util.*;

public class TestLinkedHashMap
{
	public static void main(String []args)
	{
		LinkedHashMap scores = new LinkedHashMap();
		scores.put("语文", 78);
		scores.put("数学", 89);
		scores.put("英语", 60);

		for (Object key : scores.keySet()){
			System.out.print(key + "--->");
			System.out.print(scores.get(key) + "\n");
		}
	}
}
