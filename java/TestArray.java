import java.util.Arrays;
public class TestArray
{
	public static void main(String[] args)
	{
		int[] a = new int[100];
		for (int i = 0; i < a.length; i++){
			a[i] = i+1;
		}
		for (int s : a){
			System.out.print(s + " ");
		}
		System.out.println();
		System.out.print(Arrays.toString(a));
		int[] newA = Arrays.copyOf(a, a.length * 2);
		for (int i = 0; i < newA.length; i++){
			System.out.print(newA[i] + " ");
		}
		System.out.println();
	}
}
