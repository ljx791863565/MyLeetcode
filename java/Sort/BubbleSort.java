/*
   冒泡排序
   稳定
   时间复杂度 O(n^2)
   空间复杂度 1
   */
public class BubbleSort{
	public static void main(String []argv){
		long startTime = System.currentTimeMillis();
		int [] num = new int [10000];
		for (int i = 0; i < 10000; i++){
			num[i] = (int)(Math.random() * 10000);
		}
		System.out.println();
		sort(num, num.length);
		long endTime = System.currentTimeMillis();

		for (int n : num){
			System.out.print(n + " ");
		}
		System.out.println();
		System.out.println(endTime - startTime + "ms");
	}
	public static void sort(int []num, int n){
		for (int i =0 ; i < n; i++){
			for (int j = 0; j < n-i-1; j++){
				if (num[j] > num[j+1]){
					int tmp = num[j];
					num[j] = num[j+1];
					num[j+1] = tmp; 
				}
			}
		}
	}
}
