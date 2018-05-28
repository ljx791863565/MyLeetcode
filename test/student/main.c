#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>


int main()
{
	int choose;
	while (1){
		print_menu();	//这个函数用来打印主界面
		scanf("%d", &choose);
		switch (choose)
		{
			case 1:
				Register();	//注册
				break;
			case 2:
				Login();	//登录
				break;
			case 3:
				{
					printf("系统在3s后退出...\n");
					sleep(3);
					return 0;
				}
			default	:
				{
					printf("输入有误请重新输入...");
					break;
				}
		}
	}

	return 0;
}
