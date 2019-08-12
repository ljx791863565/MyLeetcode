#include <iostream>

int main()
{
	int currVal = 0;
	int val = 0;
	int  i = 1;
	if (std::cin >> currVal){
		while (std::cin >> val){
			if (val == currVal){
				i++;
			}else{
				std::cout << currVal << "occurs " << i << "times" << std::endl;
				currVal = val;
				i = 1;
			}
		}
		std::cout << currVal << "occurs " << i << "times" << std::endl;
	}
}
