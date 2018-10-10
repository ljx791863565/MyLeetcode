#include <iostream>
using namespace std;
int i = 1;
class Widget
{
public:
	Widget()
	{
		cout << "init" << endl;
	}
	Widget(const Widget&)
	{
		cout << i++ << "-- copy init" << endl;
	}
};

Widget f(Widget u)
{
	Widget v(u);
	Widget w = v;
	return w;
}

int main()
{
	Widget x;
	Widget y = f(f(x));
//	f(f(x));
}
