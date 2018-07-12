/*
   如果一个类始终只能创建一个实例，叫单例类
   */

public class Singleton{
	private static Singleton instance;
	private Singleton()
	{

	}
	public static Singleton getInstance(){
		if (instance == null){
			instance = new Singleton();
		}
		return instance;
	}
}
