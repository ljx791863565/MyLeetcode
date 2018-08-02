import java.awt.*;

public class TestFlowLayout
{
	public static void main(String []args)
	{
		Frame f = new Frame("测试窗口");
		f.setLayout(new FlowLayout(0, 20, 5));
		for (int i = 0; i < 10; i++){
			f.add(new Button("按钮" + i));
		}
		f.pack();
		f.setVisible(true);
	}
}
