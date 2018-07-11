public class Wolf{
	private Animal a;
	public Wolf(Animal a){
		this.a = a;
	}
	public void bearch(){
		a.bearch();
	}
	public void run(){
		System.out.println("run...");
	}
}
