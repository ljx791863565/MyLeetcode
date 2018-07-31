public class TestStringBuilder
{
	public static void main(String []args)
	{
		StringBuilder sb = new StringBuilder();
		sb.append("java");
		System.out.println(sb);
		sb.insert(0, "hello");
		System.out.println(sb);
		sb.replace(5, 6, ",");
		System.out.println(sb);
		sb.delete(5, 6	);
		System.out.println(sb);
	}
}
