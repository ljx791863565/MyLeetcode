#include "student.h"

int main()
{
	int choice, i = 0;
	bool quit = false;
	cout << "****************************************************" << endl;
	StudentMassage Grade;
	while (!quit){
		system("Cls");
		Grade.ShowMenu();
		cin >> choice;
		switch (choice){
			case 0:
				quit = true;
				break;
			case 1:
				Grade.AddItem();
				break;
			case 2:
				Grade.DisPlay();
				break;
			case 3:
				Grade.Sort();
				break;
			case 4:
				Grade.Find();
				break;
			case 5:
				Grade.RemoveItem();
				break;
			case 6:
				Grade.ModifyItem();
				break;
			default :
				cout << "输入有误请重新输入... " << endl;
				break;
		}
	}
	return 0;
}
