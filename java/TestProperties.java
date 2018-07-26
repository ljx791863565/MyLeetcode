import java.util.*;
import java.io.*;
public class TestProperties
{
	public static void main(String []args) throws Exception
	{
		Properties pro = new Properties();
		pro.setProperty("username", "root");
		pro.setProperty("passwd", "123");
		pro.store(new FileOutputStream("a.ini"), "comment line");

		Properties pro2 = new Properties();
		pro2.setProperty("gender", "male");

		pro2.load(new FileOutputStream("a.ini"));

		System.out.println(pro2);
	}
}
