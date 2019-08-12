import java.math.*;
public class Arith
{
	private static final int DEF_DIV_SCALE = 10;
	private Arith(){}
	public static double add(double v1, double v2)
	{
		BigDecimal b1 = BigDecimal.valueOf(v1);
		BigDecimal b2 = BigDecimal.valueOf(v2);
		return b1.add(b2).doubleValue();
	}
	public static double sub(double v1, double v2)
	{
		BigDecimal b1 = BigDecimal.valueOf(v1);
		BigDecimal b2 = BigDecimal.valueOf(v2);
		return b1.subtract(b2).doubleValue();
	}
	/**
		不知道为什么会报错multiply无法识别
	public static double mul(double v1, double v2)
	{
		BigDecimal b1 = BigDecimal.valueOf(v1);
		BigDecimal b2 = BigDecimal.valueOf(v2);
		return multiply(b2).doubleValue();
	}
	*/
	public static double div(double v1, double v2)
	{
		BigDecimal b1 = BigDecimal.valueOf(v1);
		BigDecimal b2 = BigDecimal.valueOf(v2);
		return  b1.divide(b2, DEF_DIV_SCALE, BigDecimal.ROUND_HALF_UP).doubleValue();
	}
	public static void main(String []args)
	{
		System.out.println("0.05 + 0.01 = " + Arith.add(0.02, 0.01));
		System.out.println("0.05 - 0.02 = " + Arith.sub(0.05, 0.01));
	//	System.out.println("4.105 * 100 = " + Arith.mul(4.105, 100));
		System.out.println("123.3 / 100 = " + Arith.div(123.3, 100));
	}
}
