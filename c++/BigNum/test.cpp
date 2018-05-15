#include "BigNum.h"

int main()
{
	BigNum s;
	BigNum s1("213143214");
	cout << s1 << endl;
	BigNum s2;
	cin >> s2;
	cout << s2 << endl;
	BigNum s3 = s1;
	cout << s3 << endl;	
	if (!(s1 == s3)){
		std::cout << "s3 == s1" << std::endl
	}else{
		std::cout << "s3 != s1" << std::endl;
	}
	return 0;
}
