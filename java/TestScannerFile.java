import java.util.Scanner;
import java.io.*;
public class TestScannerFile
{
	public static void main(String []args)throws Exception
	{
		Scanner sc = new Scanner(new File("ShowHand.java"));
		System.out.println("Show ShowHand.java: ");
		while (sc.hasNextLine()){
			System.out.println(sc.nextLine());
		}
	}
}
