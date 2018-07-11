public class TestAnimal{
	public static void main(String []args){
		Animal a = new Animal();
		Bird b = new Bird(a);
		b.bearch();
		b.fly();
	
		Animal a2 = new Animal();
		Wolf w = new Wolf(a2);
		w.bearch();
		w.run();
	}
}
