public enum Gender
{
	//这里的枚举类无需使用new
	//这一句相当于 public static final Gander MALE = new Gender("男");
	MALE("男"),
	FEMALE("女");
	private String name;
	//提供一个构造方法 private属性，不对外公开
	//枚举类不应该可变。所以无需判断，直接定义成static final
	private Gender(String name)
	{
		this.name = name;
	}
/*
	public void setName(String name)
	{
		switch (this)
		{
			case MALE:
				if (name.equals("男")){
					this.name = name;
				}else{
					System.out.println("参数错误");
					return;
				}
				break;
			case FEMALE:
				if (name.equals("女")){
					this.name = name;
				}else {
					System.out.println("参数错误");
					return;
				}
				break;
		}
	}
	*/
	//暴露getName接口来访问枚举的两个固定属性
	public String getName()
	{
		return this.name;
	}
}
