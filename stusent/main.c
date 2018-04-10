#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char** argv)
{
	ST *head = NULL;
	system("clear");
	Version_info();
	sleep(2);
	while (1){
		switch (menu())
		{
			case 1:
				Login();
				break;
			case 2:
				Register(head);
				break;
			case 3:
//				Quit();
				break;
//			default:
//				DefaultShow();
		}			
	}
	return 0;
}
