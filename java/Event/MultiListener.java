import java.awt.*;

public class MultiListener
{
	private Frame f = new Frame("测试");
	private TextArea ta = new TextArea(6, 40);
	private Button b1 = new Button("按钮一");
	private Button b2 = new Button("按钮二");

	public void init()
	{
		FirstListener f1 = new FirstListener();
		b1.addActionListener(f1);
		b1.addActionListener(new SecondListener());
		b2.addActionListener(f1);
		f.add(ta);
		Panel p = new Panel();
		p.add(b1);
		p.add(b2);
		f.add(p, BorderLayout.SOUTH);
		f.pack();
		f.setVisible(true);
	}
	class FirstListener implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			ta.append("第一个监听事件被触发，事件源是：" + e.getActionCommand() + "\n");
		}
	}
	class SecondListener implements ActionListener
	{
		public void acctionPerformed(ActionEvent e)
		{
			ta.append("单击了" + e.getActionCommand() + "按钮");
		}
	}
	public static void main(String []args)
	{
		MultiListener().init();
	}
}
