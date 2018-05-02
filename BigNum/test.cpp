#include "bignum.h"

int main()
{
	BigNum b1("8329487777777777742836842777777");
	cout << b1 << endl;
	
	BigNum b2("888800000000000000000000000002");
	cout << b2 << endl;

	BigNum b3 = b2;
	cout << b3 << endl;
	
	BigNum b4(123);
	BigNum b5(345);
	BigNum result = b4 + b5;
	cout << result << endl;
	return 0;
}
