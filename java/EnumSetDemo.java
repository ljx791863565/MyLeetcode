import java.util.*;

public class EnumSetDemo
{
	public static void main(String []args)
	{
		EnumSet et = EnumSet.allOf(SeasonEnum.class);
		System.out.println(et);

		EnumSet et2 = EnumSet.noneOf(SeasonEnum.class);
		System.out.println(et2);

		et2.add(SeasonEnum.SUMMER);
		et2.add(SeasonEnum.WINTER);
		System.out.println(et2);

		EnumSet et3 = EnumSet.of(SeasonEnum.SPRING, SeasonEnum.SUMMER);
		System.out.println(et3);

		EnumSet et4 = EnumSet.range(SeasonEnum.SUMMER, SeasonEnum.WINTER);
		System.out.println(et4);

		EnumSet et5 = EnumSet.complementOf(et4);
		System.out.println(et5);
	}
}
