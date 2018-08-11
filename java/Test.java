
import java.util.*;
public class Test{
	public static void main(String [] argv){
		System.out.println("hello world!");
		int [] array = new int [] {4, 5, 6, 7};
		for (int i=0; i<array.length; i++){
			System.out.println(array[i]);
		}
		for (int at : array){
			System.out.println(at);
		}
		System.out.println(new Date());
		String s = new Date().toString();
		System.out.println(s);
	}
}
