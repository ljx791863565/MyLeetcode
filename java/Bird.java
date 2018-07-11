class Bird{
	private Animal a;
	public Bird(Animal a){
		this.a = a;
	}
	public void bearch(){
		a.bearch();
	}
	public void fly(){
		System.out.println("i can fly");
	}
}
