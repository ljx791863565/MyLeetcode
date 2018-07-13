public abstract class Shape{
	{
		System.out.println("Shape init...");
	}
	private String color;
	public abstract double calPerimeter();
	public abstract String getType();
	public Shape(){}
	public Shape(String color){
		this.color = color;
	}
	public void setColor(String color){
		this.color = color;
	}
	public String getColor(){
		return this.color;
	}
}
