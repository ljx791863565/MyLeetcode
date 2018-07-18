public class OutputFactory
{
	public Output getOutput()
	{
		return new BetterPrinter();
	}
	public static void main(String []args)
	{
		OutputFactory of = new OutputFactory();
		Computer c = new Computer(of.getOutput());
		c.keyIn("轻量级J2EE企业应用实战");
		c.keyIn("Struts2 权威指南");
		c.print();
	}
}
