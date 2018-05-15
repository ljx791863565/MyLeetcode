#ifndef __BIGNUM__H__
#define __BIGNUM__H__

using namespace std;
#include <iostream>
#include <string>
class BigNum
{
friend istream& operator>>(istream &in, BigNum &b);
friend ostream& operator<<(ostream &out, const BigNum &b);
friend bool operator==(const BigNum &lhs, const BigNum &lhs);
friend bool operator!=(const BigNum &lhs, const BigNum &lhs);
public:
	BigNum() = default;
	BigNum(const string &s) : str(s)
	{
		count = s.size();
	}
	BigNum& operator=(const BigNum &b);
private:
	int count;
	string str;
};
BigNum& BigNum:: operator=(const BigNum &b)
{
	str = b.str;
	count = b.count;
	return *this;
}
istream& operator>>(istream &in, BigNum &b)
{
	in >> b.str;
	return in;
}
ostream& operator<<(ostream &out, const BigNum &b)
{
	out << b.str ;
	return out;
}

bool operator==(const BigNum &lhs, const BigNum &rhs)
{
	return lhs.str == rhs.str;
}

bool operator!=(const BigNum &lhs, const BigNum &rhs)
{
	return !(lhs == rhs);
}
#endif //__BIGNUM__H__

