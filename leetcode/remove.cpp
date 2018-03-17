#include <iostream>

class Solution{
public:
	int RemoveElement(int *arr, int n, int elem)
	{
		int i = 0, j = 0;
		for (i=0; i<n; ++i){
			if (arr[i] == elem){
				continue;
			}

			arr[j] = arr[i];
			++j;
		}

		return j;
	}

	void show(int *arr, int n)
	{
		for (int i=0; i<n; ++i){
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
};

int main()
{
	int arr[6] = {1, 3, 3, 4, 7, 9};
	Solution s;
	s.show(arr, 6);
	int n = s.RemoveElement(arr, 6, 3);
	std::cout << n << std::endl;
	s.show(arr, n);
	return 0;
}
