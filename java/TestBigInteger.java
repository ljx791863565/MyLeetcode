import java.util.*;
import java.math.*;
public class TestBigInteger
{
	public static void main(String []args)
	{
		Scanner in = new Scanner(System.in);
		System.out.println("how many numbers do you need to draw?");
		int k = in.nextInt();
		System.out.println("what is the highest number you can draw?");
		int n = in.nextInt();

		BigInteger lotterOdds = BigInteger.valueOf(1);
		for (int i = 1; i <= k; i++)
		{
			lotterOdds = lotterOdds.multiply(BigInteger.valueOf(n - i + 1)).divide(BigInteger.valueOf(i));
		}
		System.out.println("You odds are 1 / " + lotterOdds + ". Good luck");
	}
}
