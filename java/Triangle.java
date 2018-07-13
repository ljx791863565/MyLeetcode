public class Triangle extends Shape{
	private double a;
	private double b;
	private double c;

	public Triangle(String color, double a, double b, double c){
		super(color);
		this.setSides(a, b, c);
	}
	public void setSides(double a, double b, double c){
		if (a + b <= c || a + c <= b || b + c <= a){
			System.out.println("无法构成三角形");
			return ;
		}
		this.a = a;
		this.b = b;
		this.c = c;
	}
	
	public double calPerimeter(){
		return a + b + c;
	}
	public String getType(){
		return "Triangle";
	}

}
