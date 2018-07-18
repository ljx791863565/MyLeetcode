public class Season
{
	private final String name;
	private final String desc;
	public static final Season SPRING = new Season("春天", "踏青");
	public static final Season SUMMER = new Season("夏天", "游泳");
	public static final Season FALL = new Season("秋天", "收获");
	public static final Season WINTER = new Season("冬天", "冬眠");

	public static Season getSeason(int seasonNum)
	{
		switch (seasonNum)
		{
			case 1:
				return SPRING;
			case 2:
				return SUMMER;
			case 3:
				return FALL;
			case 4:
				return WINTER;
			default:
				return null;
		}
	}
	private Season(String name, String desc)
	{
		this.name = name;
		this.desc = desc;
	}
	public String getName()
	{
		return this.name;
	}
	public String getDesc()
	{
		return this.desc;
	}
}
