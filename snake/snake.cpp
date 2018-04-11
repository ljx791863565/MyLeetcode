#include "snake.h"

struct snake
{
	int x;
	int y;
};
class Snake
{
public:
	Snake()
	{
		length = 3;
		s[2].x = 10;
		s[2].y = 10;
		s[1].x = 9;
		s[1].y = 10;
		s[0].x = 8;
		s[0].y = 10;
		
		up = down = right = left = 0;
	}

	~Snake(){}

	void display

private:
	struct snake s[100];		//定义蛇身长度上限100
	int length;					//当前蛇身长度
	int x3,y3;					//食物坐标
	int up, dowm, right, left;	//蛇的上下左右移动状态
};
//游戏框架
void Frame()
{
	system("clear");

}
//主界面
void Menu()
{
	printf
}
