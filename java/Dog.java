public class Dog{
	public String color;

	public void jump()
	{
		System.out.println("jump");
	}
	public void run()
	{
		jump();
		System.out.println("run");
	}
	public static void down()
	{
		System.out.println("down");
	}
	public void setColor()
	{
		this.color = "black";
	}
	public String getColor()
	{
		return color;
	}
	public static void main(String []argv)
	{
		Dog d = new Dog();
		d.jump();
		d.run();
		down();
		d.setColor();
		System.out.println(d.getColor());
	}
}
