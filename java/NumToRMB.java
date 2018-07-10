/*
   将一个浮点数的RMB值以书面形式写出来
   */
import java.util.Arrays;
public class NumToRMB{
	private String []WordArr = {"零",  "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
	private String []UnitArr = {"拾", "佰", "仟"};

	//分离整数部分和小数部分，数组形式返回，数组的第一个元素是整数，第二个元素是小数部分*100，即只取小数点后两位
	private String[] divide(double num)
	{
		long zhengshu = (long)num;
		//小数部分*100 后取整
		long xiaoshu = Math.round((num - zhengshu)*100);
		return new String[] {zhengshu  + "" , String.valueOf(xiaoshu)};
	}
	
	//把一个四位数数字改成汉字字符串返回
	private String toWordStr(String numStr)
	{
		String result = "";
		int numLen = numStr.length();
		for (int i = 0; i < numLen; i++){
			//ASCII码 '4' 转换成数字4需要-48
			int num = numStr.charAt(i) - 48;
			if (i != numLen - 1 && num != 0){
				result += WordArr[num] + UnitArr[numLen - 2 - i];
			}else{
				result += WordArr[num];
			}
		}
		return result;
	}
	public static void main(String []argv){
		NumToRMB test = new NumToRMB();
		System.out.println(Arrays.toString(test.divide(236711125.123)));
		String []arr = test.divide(23456789.12);
//		System.out.println(test.toWordStr(arr[0]) + "块" + test.toWordStr(arr[1]));
		System.out.println(test.toWordStr("3456"));
	}
}
