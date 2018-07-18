//接口有public修饰，和类一样需要和源文件名一致
public interface Output
{
	//常量默认 public static final修饰，即该量是公共的接口属性并且不了更改
	//不同的包内的类也可以访问该接口属性,但要指明包全名
	int MAX_CACHE_LINE = 50;

	//接口方法默认是public abstract修饰
	void out();
	void getData(String msg);	

	//内部类和枚举类默认是public static修饰
	//接口没有构造器和初始化块
}
