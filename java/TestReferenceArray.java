
public class TestReferenceArray{
	public static void main(String [] argv){
		person [] students;	
		students = new person[2];

		person zhang = new person();
		zhang.age = 24;
		zhang.heigth = 187;

		person lee = new person();
		lee.age = 23;
		lee.heigth = 181;

		students[0] = zhang;
		students[1] = lee;

		lee.info();
		students[0].info();
	}
}
