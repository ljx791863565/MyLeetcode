
public class person{
	public int age;
	public double heigth;
	public void info()
	{
		System.out.println("age = " + age + ", heigth = " + heigth);
	}
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
}

