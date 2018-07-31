import java.util.*;
public class TestScannerKeyBoard
{
	public static void main(String []args)
	{
		Scanner sc = new Scanner(System.in);
		//Scanner默认从键盘读取时空格换行
		//下面函数改变换行行为 使回车换行
		sc.useDelimiter("\n");
		while (sc.hasNext()){
			System.out.println("KeyBoard " + sc.next());
		}
	}
}
