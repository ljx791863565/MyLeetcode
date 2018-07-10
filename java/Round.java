/**
*Description
*<br/>Copyright (C) , 2018-7-2
*<br/>Data
*<br/>Program Name
*@author Jiaxing Liao
*@version 1.1
*/

public class Round
{
	/*
	* 绘制圆形图像，输入半径，输出图形
	*/
	private static int r;
	Round(int r)
	{
		this.r = r;
	}
	public static void paint()
	{
		//假定圆心在(r, r)处
		int x = 0;	//x的坐标开始
		int y = r * 2;	//y的坐标开始
		int c = 0;	//中间格数量
		int z = 2;	//递减

		for (int i = y; i >= 0; i -= z){
			x = getX(r, y);
			System.out.println(getSpace(x) + "*");
			c = (r - x) * 2;
			System.out.println(getSpace(c) + "*");
			y -= z;
		}
	}
	/*
	*获取画*的位置 
	*/
	public static int getX(int r, int y)
	{
		int h = y - r;
		double l = Math.sqrt((r * r) - (h * h));
		return (int)Math.round(r-l);
	}
	/*
	*画空格
	*/
	public static String getSpace(int i)
	{
		String s = "";
		for (int j = 0; j < i; j++){
			s += " ";
		}
		return s;
	}
	public static void main(String [] argv)
	{
		new Round(10).paint();
	}
}
