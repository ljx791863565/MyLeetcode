#include <iostream>

int main()
{
	int var = 50;
	int sum = 0;
	while (var <= 100){
		sum += var;
		var ++;
	}

	std::cout << "sum = " << sum << std::endl;

	return 0;
}
