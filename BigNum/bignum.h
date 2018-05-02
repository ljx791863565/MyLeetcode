#ifndef __BIGNUM__H__
#define __BIGNUM__H__

#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef long long INT_64;
const long long INT_64_MAX = 0x7fffffffffffffff;	//9223372036854775807
const long long INT_64_MIN = 0x8000000000000000;	//-9223372036854775808
class BigNum
{
friend ostream & operator<<(ostream &os, BigNum &big);

friend BigNum operator+(const BigNum &left, const BigNum &right);
friend BigNum operator-(const BigNum &left, const BigNum &right);
friend BigNum operator*(const BigNum &left, const BigNum &right);
friend BigNum operator/(const BigNum &left, const BigNum &right);
public:
	BigNum(INT_64 value);
	BigNum(const char *num_str);
	BigNum(const BigNum &big);
	~BigNum()
	{
		_strData = "\0";
		_value = 0;
	}
	BigNum & operator=(const BigNum &big);
private:
	bool IsINT64Overflow() const;
	string _strData;
	INT_64 _value;
};

string Add(const string &left, const string &right);
string Sub(const string &left, const string &right);
string Mul(const string &left, const string &right);
string Div(const string &left, const string &right);

bool IsLeftBig(const char *left, int lSize, const char *right, int rSize);
char SubLoop(char *left, int lSize, const char *right, int *rSize);

BigNum::BigNum(INT_64 value)
	:_value(value)
{
	_strData.resize(21, '0');
	sprintf((char *)_strData.c_str(), "%+lld", value);
}

BigNum::BigNum(const char *num_str)
{
	_value = 0;
	if (NULL == num_str){
		return ;
	}
	char *str = (char *)num_str;
	while (isspace(*str)){
		++str;
	}
	char symbol = '+';
	if ('-' == *str || '+' == *str){
		symbol = *(str++);
	}
	while ('0' == *str){
		++str;
	}
	_strData.resize(strlen(str) +1);

	char *dst = (char *)_strData.c_str();
	*(dst++) = symbol;

	while (*str >= '0' && *str <= '9'){
		_value = _value *10 + *str - '0';
		*(dst++) = *(str++);
	}
	if ('-' == symbol){
		_value = 0 - _value;
	}

	_strData.resize(strlen(_strData.c_str()));

	if (_strData.size() == 1){
		_strData.append(1, 0);
	}
}

BigNum::BigNum(const BigNum &big)
{
	_value = big._value;
	_strData = big._strData;
}

BigNum & BigNum::operator=(const BigNum &big)
{
	if (this != &big){
		_value = big._value;
		_strData = big._strData;
	}
	return *this;
}

bool BigNum::IsINT64Overflow() const
{
	if (_strData.size() > 20){
		return true;
	}
	if (_strData.size() == 20){
		string max("9223372036854775807");
		string min("-9223372036854775808");
		char *tmp = (char *)_strData.c_str();
		if ('-' == tmp[0]){
			return _strData < min;
		}else{
			return _strData > max;
		}
	}

	return false;
}

ostream &operator<<(ostream &os, BigNum &big)
{
	if (!big.IsINT64Overflow()){
		os << big._value;
	}else{
		const char *tmp = big._strData.c_str();
		if ('+' == *tmp){
			++tmp;
		}
		cout << tmp;
	}
}

BigNum operator+(const BigNum &left, const BigNum &right)
{
	//1.左右操作数均未溢出
	if (!left.IsINT64Overflow() && !right.IsINT64Overflow()){
		//同号且溢出情况
		if (((left._value > 0 && right._value > 0) && (INT_64_MAX - left._value < right._value))
				|| (left._value < 0 && right._value < 0) && (INT_64_MIN - left._value > right._value)){
			//do nothing
		}
		//不会溢出
		else {
			return BigNum(left._value + right._value);
		}
	}
	//2.左右操作数有一个溢出或两个都溢出
	return BigNum(Add(left._strData, right._strData).c_str());
}

string Add(const string &left, const string &right)
{
	int LSize = left.size();
	int RSize = right.size();

	const char *Left = left.c_str();
	const char *Right = right.c_str();

	char symbol;
	//同号
	if (*Left == *Right){
		if (LSize < RSize){
			swap(LSize, RSize);
			swap(Left, Right);
		}

		symbol = *Left;
		string result;
		result.resize(LSize+1);
		char *ret = (char *)result.c_str();
		ret[0] = symbol;

		int carry = 0;
		int i;
		for (i=1; i<LSize; ++i){
			int sum;
			if (i < RSize){
				sum = Left[LSize - i] - '0' + Right[RSize - i] - '0' + carry;
			}else {
				sum = Left[LSize - i] - '0' + carry;
			}
			carry = sum / 10;
			sum %= 10;
			ret[LSize + i - 1] = sum + '0';
		}
		ret[1] = carry + '0';
		return result;
	}
	//异号
	else {
		string l(Left);
		string r(Right);

		if ('-' == *Left){
			char *tmp = (char *)l.c_str();
			tmp[0] = '+';
			return Sub(r, l);	//转换为同正号相减
		}else {
			char *tmp = (char *)r.c_str();
			tmp[0] = '+';
			return Sub(l, r);
		}
	}
}

BigNum operator-(const BigNum &left, const BigNum &right)
{
	//1.左右操作数均未溢出
	if (!left.IsINT64Overflow() && !right.IsINT64Overflow()){
		//同号且溢出情况
		if (((left._value > 0 && right._value > 0) && (INT_64_MAX - left._value < right._value))
				|| (left._value < 0 && right._value < 0) && (INT_64_MIN - left._value < right._value)){
			//do nothing
		}
		//不会溢出
		else {
			return BigNum(left._value - right._value);
		}
	}
	//2.左右操作数有一个溢出或两个都溢出
	return BigNum(Sub(left._strData, right._strData).c_str());
}

string Sub(const string &left, const string &right)
{
	string left_tmp = left;
	int LSize = left.size();
	int RSize = right.size();

	const char *Left = left_tmp.c_str();
	const char *Right = right.c_str();

	char symbol;
	//同号
	if (*Left == *Right){
		//计算最终结果符号
		symbol = '-';
		if ('+' == *Right){
			if ((left.size() > right.size() || (left.size() == right.size() && left > right))){
				symbol = '+';
			}
		}else {
			if ((left.size() < right.size()) || (left.size() == right.size() && left < right)){
				symbol = '+';
			}
		}
		if (LSize < RSize){
			swap(LSize, RSize);
			swap(Left, Right);
		}

		string result;
		result.resize(LSize);
		char *dst = (char *)result.c_str();
		dst[0] = symbol;

		int carry = 0;
		int sub;
		int i;
		for (i=1; i<LSize; ++i){
			sub -= carry;
			if (i < RSize){
				sub = Left[LSize - i] -  Right[RSize - i];
			}else {
				sub = Left[LSize - i] - '0';
			}
			if (sub < 0){
				if (left[LSize - i - 1] >= '0' && left[LSize - i - 1] <= '9'){
					carry = 1;
					sub += 10;
				}else {
					sub = 0 - sub;
				}
			}else {
				carry = 0;
			}
			dst[LSize - i] = sub + '0';
		}
		return result;
	}
	//异号
	else {
		if ('+' == *Left){
			string r(right);
			char *tmp = (char *)r.c_str();
			tmp[0] = '+';
			return Add(left, r);
		}else {
			string l(left);
			char *tmp = (char *)l.c_str();
			tmp[0] = '+';
			string ret = Add(l, right);
			tmp = (char *)ret.c_str();
			if ('-' == *tmp){
				*tmp = '+';
			}else {
				*tmp = '-';
			}
			return ret;
		}
	}
}







#endif //__BIGNUM__H__
