/*
   桶排序
   不稳定
   时间复杂度 O(1)
   空间复杂度 n^2
   */
public class BucketSort{
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
		int max = 0;
		for (int i = 0; i < n; i++){
			if (max < num[i]){
				max = num[i];
			}
		}
		int []tmpBuf = new int[max+1];
		for (int i = 0; i < max +1; i++){
			tmpBuf[i] = 0;
		}	
		for (int i =0 ; i < n; i++){
			tmpBuf[num[i]]++; 
		}
		for (int i = 0, j = 0; i < max+1; i++){
			while (tmpBuf[i] != 0){
				num[j++] = i;
				tmpBuf[i]--;
			}
		}	
	}
}
