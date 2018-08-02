import java.awt.*;
public class TestBorderLayout
{
	public static void main(String []args)
	{
		Frame f = new Frame("测试窗口");
		f.setLayout(new BorderLayout(30, 5));
		f.add(new Button("南"), BorderLayout.SOUTH);
		f.add(new Button("北"), BorderLayout.NORTH);
		Panel p = new Panel();
		p.add(new TextField(20));
		p.add(new Button("单击我"));
		f.add(p);
	//	f.add(new Button("中"));
		f.add(new Button("东"), BorderLayout.EAST);
	//	f.add(new Button("西"), BorderLayout.WEST);

		f.pack();
		f.setVisible(true);
	}
}
