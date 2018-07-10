public class Ostrich extends Bird{
	//覆盖父类中的方法 this引用
	public static void fly(){
		System.out.println("i can not fly");
	}
	public void callOverridedMethon()
	{
		//直接父类对象的默认引用
		//super关键字可以在子类中直接调用父类方法，而不是覆盖
		//super引用
		super.fly();
	}
	public static void main(String []args){
		Ostrich os = new Ostrich();
		os.fly();
		os.callOverridedMethon();
	}
}
