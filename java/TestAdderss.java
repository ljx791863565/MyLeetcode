public class TestAdderss{
	public static void main(String []args){
		Adderss a1 = new Adderss();
		Adderss a2 = new Adderss();
		System.out.println(a1.hashCode());
		System.out.println(a2.hashCode());

		System.out.println(a1 == a2);
	}
}
