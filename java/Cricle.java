public class Cricle extends Shape{
	private double radius;
	public Cricle(String color, double radius){
		super(color);
		this.radius = radius;
	}
	public void setRadius(double radius){
		this.radius = radius;
	}
	public double getRadius(){
		return this.radius;
	}
	public double calPerimeter(){
		return 2 * Math.PI * radius;
	}
	public String getType(){
		return "Cricle";
	}
	public static void main(String []args){
		Shape s1 = new Triangle("black", 3, 4, 5);
		Shape s2 = new Cricle("white", 5);

		System.out.println(s1.calPerimeter());
		System.out.println(s1.getType());
		System.out.println(s2.calPerimeter());
		System.out.println(s2.getType());
	}
}
