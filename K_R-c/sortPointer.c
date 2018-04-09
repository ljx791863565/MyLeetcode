#include <stdio.h>
#include <string.h>

int main()
{
	//指针数组
	char phone*[20] = {
		"Apple", "Samsung", "Zppo", "Biaomi", "Feizu", "Nokia"
	};

	int i, j;
	char *p[6];
	for (i=0; i< 6; ++i){
		p[i] = phone[i];
	}
	for (i =0; i<6; ++i){
		for (j=0; j< 6-i-1; j++){
			if (strcmp(p[j], p[j+1])){
				char *tmp = p[j];
				p[j] = p[j+1];
				p[j+1] = tmp;
			}
		}
	}
	for (i=0; i<6; ++i){
		printf("%s \n", p[i]);
	}
	return 0;
}
