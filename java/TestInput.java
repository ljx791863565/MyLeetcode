import java.util.*;
import java.io.*;
public class TestInput
{
	public static void main(String []args)
	{
		Scanner in = new Scanner(System.in);
		System.out.println("what is you name");
		String name = in.nextLine();
		System.out.println("how old are you");
		int age = in.nextInt();
		System.out.println("hello " + name + ".next year you will be " + (age+1));
	
		Console cons = System.console();
		String username = cons.readLine("User name：");
		char[] passwd = cons.readPassword("Passwd: ");
		System.out.println("username is :" + username);
		for (int i = 0; i < passwd.length; i++){
			System.out.print(passwd[i]);
		}
		System.out.println();
	}
}
