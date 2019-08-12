#include <iostream>

int main()
{
	int v1, v2;
	std::cout << "please inter two numbers " << std::endl;

	std::cin>> v1 >> v2;

	if (v1 > v2){
		while (v1 >= v2){
			std::cout << v1 << std::endl;
			v1 --;
		}
	}else {
		while (v1 <= v2){
			std::cout << v1 << std::endl;
			v1++;
		}
	}
	return 0;
}
