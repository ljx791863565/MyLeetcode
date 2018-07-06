public class arrayInRam{
	public static void main(String [] argv){
		int [] a = {3, 5, 7};
		int [] b = new int [4];
		System.out.println("a.lengrh = " + a.length);
		System.out.println("b.length = " + b.length);
		for (int i = 0; i < a.length; i++){
			System.out.println(a[i]);
		}
		for (int j = 0; j < b.length; j++){
			System.out.println(b[j]);
		}
		b = a;
		System.out.println("new b.length = " + b.length);
	}
}
