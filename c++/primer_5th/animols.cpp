#include <iostream>

using namespace std;

class Animol
{
	virtual void bark() = 0;
	string color;
	char sex;
};

class Cat : public Animol
{
public:
	Cat(string color, char s)
	{
		color = color;
		sex = s;
	}
	void bark()
	{
		cout << "miao..." << endl;
	}
};

class Dog : public Animol
{
public:
	Dog(string color, char s)
	{
		color = color;
		sex = s;
	}
	void bark()
	{
		cout << "wang..." << endl;
	}
};
int main()
{
	Dog *p = new Dog;
	return 0;
}
