
public class SubClass extends Base{
	public String book = "疯狂java讲义";
	public void test(){
		System.out.println("子类覆盖父类的方法");
	}
	public void sub(){
		System.out.println("子类的普通方法");
	}
	public static void main(String []args){
		Base bc = new Base();
		System.out.println(bc.book);
		bc.base();
		bc.base();

		SubClass sc = new SubClass();
		System.out.println(sc.book);
		sc.base();
		sc.test();

		Base plhymorphismBc = new SubClass();
		System.out.println(plhymorphismBc.book);
		plhymorphismBc.test();
	}
}
