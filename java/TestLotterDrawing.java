import java.util.*;
public class TestLotterDrawing
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		System.out.println("how many numbers do you need draw?");
		int k = in.nextInt();

		System.out.println("what is the highest number you can draw?");
		int n = in.nextInt();

		int[] number = new int[n];
		for (int i = 0; i < number.length; i++){
			number[i] = i + 1;
		}

		int[] result = new int[k];
		for (int i = 0; i < result.length; i++){
			int r = (int)(Math.random() * n);
			result[i] = number[r];
			number[r] = number[n - 1];
			n--;
		}

		Arrays.sort(result);
		System.out.println("Bet the following combination. it will make you rich.");
		for (int r : result){
			System.out.println(r);
		}
	}
}
