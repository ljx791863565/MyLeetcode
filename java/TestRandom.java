import java.util.*;
public class TestRandom
{
	public static void main(String []args)
	{
		Random rand = new Random();
		System.out.println("rand.nextBoolean() :" + rand.nextBoolean());
		byte[] buffer = new byte[16];
		rand.nextBytes(buffer);
		System.out.println(Arrays.toString(buffer));
		System.out.println("rand.nextDouble() :" + rand.nextDouble());
		System.out.println("rand.nextFloat() :" + rand.nextFloat());
		System.out.println("rand.nextGaussian() :" + rand.nextGaussian());
		System.out.println("rand.nextInt() :" + rand.nextInt());
		System.out.println("rand.nextInt(26) :" + rand.nextInt(26));
		System.out.println("rand.nextLong() :" + rand.nextLong());
	}
}
