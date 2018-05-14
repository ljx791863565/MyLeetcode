#include <iostream>

using namespace std;
class BookInfo
{
public:
	BookInfo(){}
	BookInfo(string s, string n, double p)
		:ISBN(s), price(p), name(n)
	{

	}
	~BookInfo()
	{
		Destroy();
	}
	double total(int n);
	void display();
	void Destroy();
	friend bool isABook(const BookInfo &b1, const BookInfo &b2);
private:
	string ISBN;
	string name;
	double price;
};

void BookInfo::Destroy()
{
	ISBN = "0";
	name = "0";
	price = 0;
}
void BookInfo::display()
{
	cout << "ISBN:" << ISBN << endl;
	cout << "name:" << name << endl;
	cout << "Price:" << price << endl;
}
bool isABook(const BookInfo &b1, const BookInfo &b2)
{
	if (b1.ISBN == b2.ISBN){
		return false;
	}else{
		return true;
	}
}
double BookInfo::total(int n)
{
	return price *n;
}
int main()
{
	BookInfo s1("978-7-3-306-05941-3", "应试专项辅导", 89.8);
	s1.display();

	double tot = s1.total(5);
	cout << "total :" << tot << endl;

}
