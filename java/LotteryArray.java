public class LotteryArray
{
	public static void main(String[] args)
	{
		final int MAX = 10;
		int[][] odd = new int[MAX+1][];
		for (int n = 0; n <= MAX; n++){
			odd[n] = new int[n+1];
		}

		for (int n = 0; n < odd.length; n++){
			for (int k = 0; k < odd[n].length; k++){
				int lotteryOdd = 1;
				for (int i = 1; i <= k; i++){
					lotteryOdd = lotteryOdd * (n -i + 1) / i;
				}
				odd[n][k] = lotteryOdd;
			}
		}

		for (int[] row : odd){
			for (int o : row){
				System.out.printf("%4d", o);
			}
			System.out.println();
		}
	}
}
