#include <iostream>
#include <math.h>

using namespace std;
class Square
{
public:
	int GetNumsqe()
	{
		return numSqe;
	}
	virtual double GetPerimeter() = 0;
	virtual double GetArea() = 0;
	virtual void show() = 0;
	int numSqe;	//多边形的边数目
	double perimeter;	//多边形的周长
	double area;		//多边形的面积

};

class Trigon : public Square
{
public:
	Trigon(int a1, int a2, int a3)
	{
		numSqe = 3;
		if (a1+a2 > a3 && a1+a3 > a2 && a2+a3 > a1 && a1-a2 < 3 && a1-a3 < a2 && a2-a3 < a1){
			a = a1;
			b = a2;
			c = a3;
		}else{
			cout << "no trigon" << endl;
			return ;
		}
	}
	GetPerimeter()
	{
		return a + b + c;
	}
	GetArea()
	{
		double s = GetPerimeter() / 2;
		return s* (s-a)*(s-b)*(s-c);
	}
	show()
	{
		cout << "num = " << numSqe << endl;
		cout << "per = " << GetPerimeter() << endl;
		cout << "ares = " << GetArea() << endl;
	}
private:
	int a;
	int b;
	int c;
};
int main()
{
	Square *s = new Trigon(6, 7, 9);
	return 0;
}
