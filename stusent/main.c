#include "student.h"

int main()
{
	int num;
	while (1){
		midShow();
		printf("请输入:\n");
		scanf("%d", &num);
		switch (num){
			case 1:
				studentShow();
				break;
			case 2:
				teacherShow();
				break;
			case 3:
				rootShow();
				break;
			case 4:
				quitShow();
				break;
			default:
				defaultShow();
		}

	}
	return 0;
}
