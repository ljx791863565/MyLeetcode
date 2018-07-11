
public class person{
//	public int age;
//	public double heigth;
	private String name;
	public person(String name){
		this.name = name;
	}
	//toString方法属于Object类，所以每一个类都可以调用
	//如果程序员直接打印对象。得到的是 对象名@hashCode
	//hashCode是 6位16进制数
   //toString方法可以重载	
	public String toString(){
		return "this is the test to string " + name;
	}

	//重写equals
	public boolean equals(Object obj){
		if (this == obj){
			return true;
		}
		if (obj != null && obj.getClass() == person.class){
			person p = (person)obj;
			if (this.getldStr().equals(p.getldStr())){
				return true;
			}
		}
		return false;
	}
	public void info()
	{
	//	System.out.println("age = " + age + ", heigth = " + heigth);
		System.out.println("name is " + name);
	}
	/*
	public static void main(String []argv)
	{
		person p = new person();
		p.age = 18;
		p.heigth = 181;
//		p.info();
		person [] personArr = new person[2];
		personArr[0] = new person();
		personArr[1] = new person(); 
		personArr[0].age = 18;
		personArr[0].heigth = 188;
		personArr[1].age = 20;
		personArr[1].heigth = 172;

		for (int i = 0; i < personArr.length; i++){
			personArr[i].info();
		}
	}
	*/
}

