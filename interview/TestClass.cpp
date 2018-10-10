#include <iostream>

using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "this is animal..." << endl;
	}
	virtual ~Animal()
	{

	}
	virtual void cry() = 0;
	virtual void info() = 0;
	string color;
	int lag;
};
class Dog : public Animal
{
public:
	Dog(string aColor, int aLag)
	{
		cout << "this is a dog" << endl;
		color = aColor;
		lag = aLag;
	}
	void cry()
	{
		cout << "wang wang wang..." << endl;
	}
	void info()
	{
		cout << "this is a " << color << " fur, and has " << lag << " lags" << endl;
	}
};
int main()
{
	Dog d("black", 4);
	d.cry();
	d.info();

	return 0;
}
