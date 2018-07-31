import java.io.*;
public class TestBufferedReader
{
	public static void main(String []args) throws Exception
	{
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String  buffer = null;
		while ((buffer = bf.readLine()) != null){
			System.out.println("用户键盘输入 : " + buffer);
		}
	}
}
