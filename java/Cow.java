public class Cow
{
	private double weight;
	public Cow(double weight)
	{
		this.weight = weight;
	}
	private class CowLeg
	{
		private String color;
		private double length;

		public CowLeg(){}
		public CowLeg(String color, double length)
		{
			this.length = length;
			this.color = color;
		}
		public void setLength(double length)
		{
			this.length = length;
		}
		public double getLength()
		{
			return this.length;
		}
		public void setColor(String color)
		{
			this.color = color;
		}
		public String getColor()
		{
			return this.color;
		}
		public void info()
		{
			System.out.println("这个牛腿的颜色是 : " + color + "长度是 : " + length);
			System.out.println("这个牛的重量是 : " + weight);
		}
	}
	public void test(String color, double length)
	{
		CowLeg cs = new CowLeg();
		cs.setLength(length);
		cs.setColor(color);
		cs.info();
	}

}
