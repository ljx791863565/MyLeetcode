#include "list.h"
/*
struct Student{
	int id;
	char name[20];
	char sex;
	float score;
};
struct Link{
	struct Student stu;
	struct Link *next;
};

void print(struct Student *stu)
{
	printf("%d %s %c %.1f\n", stu->id, stu->name, stu->sex, stu->score);
}


int main()
{
	struct Student stu = {1002, "Tony", 'b', 79.6};
	
	print(&stu);
	
	return 0;
}
*/

int main()
{
	Node* head = NULL;
	head = push_back(head, 3);
	head = push_back(head, 4);
	head = push_back(head, 7);

	head = push_front(head, 8);
	head = push_front(head, 9);
	head = push_front(head, 10);

	show(head);
	Node* p = NULL;	
	Node* test = select(p, 6);
	if (test != NULL){
		printf("%d\n", test->elem);
	}else{
		printf("have no data\n");
	}

//	head = update(head, 3, 11);
//	show(head);

	head = deleteList(head, 3);
	show(head);
	return 0;
}
