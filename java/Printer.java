//接口如果省略public修饰。默认是包控制权限
interface Produce
{
	int getProduceTime();
}

//和继承不同的是，接口支持多继承，用 , 分隔开
//接口的实现用implements关键字
//接口实现必须重写所有接口方法，否则要定义为抽象类
public class Printer implements Output, Produce{
	private String [] printData = new String[MAX_CACHE_LINE];

	private int dataNum = 0;
	public void out()
	{
		while (dataNum > 0){
			System.out.println("打印机打印" + printData[0]);
			System.arraycopy(printData, 1, printData, 0, --dataNum);
		}
	}
	public void getData(String msg){
		if (dataNum >= MAX_CACHE_LINE){
			System.out.println("输出队列已满,添加失败");
		}else {
			printData[dataNum++] = msg;
		}
	}

	public int getProduceTime(){
		return 45;
	}
	public static void main(String []args){
		Output os = new Printer();
		os.getData("疯狂java讲义");
		os.getData("java并发多线程");
		os.out();

		os.getData("基于J2EE的Ajax宝典");
		os.getData("Ruby On Rails 敏捷开发最佳实践");
		os.out();

		Produce ps = new Printer();
		System.out.println(ps.getProduceTime());
		
		Object obj = ps;
	}
}
