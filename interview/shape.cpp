#include <iostream>
#include <math.h>
#define PI 3.141592
using namespace std;

class Shape
{
public:
	Shape()
	{
		cout << "Shape" << endl;
	}

	virtual double area() = 0;
	virtual double volume() = 0;
	virtual void show() = 0;

	virtual ~Shape()
	{
		cout << "~Shape" << endl;
		cout << endl;
	}
};

class Cube : public Shape
{
public:
	Cube() = default;
	Cube(int i) : l(i)
	{
		cout << "Cube" << endl;
	}
	~Cube()
	{
		cout << "~Cube" << endl;
		cout << endl;
	}
	double area()
	{
		return 6 * l * l;
	}
	double volume()
	{
		return l * l * l;
	}
	void show()
	{
		cout << "this is Cube " << endl;
		cout << "area = " << area() << endl;
		cout << "volume = " << volume() << endl;
	}
private:
	int l;
};

class Cone : public Shape
{
public:
	Cone() = default;
	Cone(int r, int h) : r(r), h(h)
	{
		cout << "Cone" << endl;
	}
	~Cone()
	{
		cout << "~Cone" << endl;
		cout << endl;
	}
	double area()
	{
		double l = r*r + h*h;
		l = sqrt(l);
		double s = PI * l * r;
		return PI * r * r + s;
	}
	double volume()
	{
		return PI * r * r * h / 3.0;
	}
	void show()
	{
		cout << "this is Cone" << endl;
		cout << "area = " << area() << endl;
		cout << "volume = " << volume() << endl;
	}
private:
	int r;
	int h;
};

class Ball : public Shape
{
public:
	Ball() = default;
	Ball(int r) : r(r)
	{
		cout << "Ball" << endl;
	}
	~Ball()
	{
		cout << "~Ball" << endl;
		cout << endl;
	}
	double area()
	{
		return 4 * PI * r * r;
	}
	double volume()
	{
		return 4.0 / 3.0 * PI * r * r * r;
	}
	void show()
	{
		cout << "this is Ball" << endl;
		cout << "area = " << area() << endl;
		cout << "volume = " << volume() << endl; 
	}
private:
	int r;
};

int main()
{
	Shape *p = new Cube(3);
	p->show();
	delete p;

	p = new Cone(1, 2);
	p->show();
	delete p;

	p = new Ball(2);
	p->show();
	delete p;

	return 0;
}
