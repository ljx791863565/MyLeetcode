#include <stdio.h>

int main()
{
	int running = 1;
	while (running){
		switch(GetMenuChoose())
		{
			case 0:
				running = 0;
				break;
			case 1:
//				printf("菜单1\n");
				AddStudent(CreateStudent());
				break;
			case 2:
				DeleteStudent(GetInputNum());
				break;
			case 3:
				ShowStudent(GetInputNum());
				break;
			case 4:
				UpdateStudent(GetInputNum());
				break;
			case 5:
				DeleteAll();
				break;
			case 6:
				ShowAll();
				break;
			case 7:
				ShowStudentCount();
				break;
			case 8:
				LoadFromFile();
				break;
			case 9:
				SaveToFile();
				break;
		}

		return 0;
			
	}
}
