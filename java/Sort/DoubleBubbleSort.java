
//package algorithm.sort;
public class DoubleBubbleSort{
	public static void main(String []argv){
		long startTime = System.currentTimeMillis();
		int [] num = new int [10000];
		for (int i =0 ; i < num.length; i++){
			num[i] = (int)(Math.random() * 10000);
		}
		System.out.println();
		sort(num, 0, num.length);
		long endTime = System.currentTimeMillis();
		for (int n  : num){
			System.out.print(n + " ");
		}
		System.out.println();
		System.out.println(endTime - startTime + "ms");		
	}
	public static void sort(int []num, int l, int n){
		if (l < n){
			int i = l;
			int j = l + 1;
			while (j < n){
				if (num[j] < num[l]){
					i++;
					int tmp = num[i];
					num[i] = num[j];
					num[j] = tmp;
				}
				j++;
			}
			int tmp = num[i];
			num[i] = num[l];
			num[l] = tmp;
			sort(num, l, i);
			sort(num, i+1, n);
		}
	}
}
