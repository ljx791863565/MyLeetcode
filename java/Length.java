import java.util.*;
public class Length
{
	public static void main(String []args)
	{
		String []str = {
			"ma", "cao", "yuan"
		};
		String a = "macaoyuan";
		
		//length属性针对数组，既声明了一个数组，可用length属性得到数组长度
		System.out.println("str.length = " + str.length);
		//length()函数针对String，可得到字符串长度
		System.out.println("a.length = " + a.length());

		
		List<Object> l = new ArrayList();
		l.add(a);
		//size()针对泛型，可得到一个泛型集合的元素个数
		System.out.println("l.size() = " + l.size());
	}
}
