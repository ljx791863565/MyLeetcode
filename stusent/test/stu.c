#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FILENAME "student.dat"

typedef struct tagStudent{
	int num;//学生编号
	char name[20];
	char sex;
	int age;
	float score;
	struct tagStudent *next;
}STUDENT, *PSTUDENT;

STUDENT g_head;//头节点

//1.显示菜单
void ShowMenu()
{
	system("clear");
	printf("\n-----------------------学生管理系统----------------------------\n");
	printf("\n\t1.添加学生信息		2.删除学生信息		3.显示某个学生信息\n");
	printf("\n\t4.修改学生信息		5.删除所有学生信息	6.显示所有学生信息\n");
	printf("\n\t7.显示信息数量		8.读取文件学生信息	9.保存信息到文件\n");
	printf("\n\t0.退出系统\n");
	printf("\n--------------------------------------------------------------\n");
}

//2.获取用户选择的菜单编号
int GetMenuChoose()
{
	int num;//保存用户输入
	ShowMenu();
	printf("请选择菜单(0~9): ");
	
	while (1 != scanf("%d", &num) || num <0 || num > 9){
		ShowMenu();
		printf("选择错误，请重新选择(0~9): ");
		fflush(stdin);
	}
	return num;
}

//5.返回指定编号学生节点的上一节点的指针
PSTUDENT GetPrevAddr(int num)
{
	PSTUDENT pstu = &g_head;
	while (pstu->next){
		if (pstu->next->num == num){
			return pstu;
		}
		pstu = pstu->next;
	}

	return NULL;
}

//3.创建一个节点，它会返回一个新创建的学生信息节点的指针
PSTUDENT CreateStudent()
{
	int sex;
	PSTUDENT pstu = (PSTUDENT)malloc(sizeof(STUDENT));
	if (!pstu){
		printf("malloc error\n");
		return NULL;
	}
	printf("请输入学生编号: ");
	while (1 != scanf("%d", &pstu->num) || GetPrevAddr(pstu->num)){
		printf("学生编号输入错误或已存在,请重新输入: ");
		fflush(stdin);
	}
	printf("请输入学生姓名 : ");
	scanf("%20s", pstu->name);
	printf("请选择学生性别('n':男 'w':女) : ");
	while (1 != scanf("%d", &sex)){
		printf("性别输入错误，请重新输入:('n':男 'w':女) ");
		fflush(stdin);
	}

	printf("请输入学生年龄: ");
	while (1 != scanf("%d" ,&pstu->age) || pstu->age < 10 || pstu->age > 35){
		printf("年龄输入错误,请重新输入(10 ~ 35) : ");
		fflush(stdin);
	}
	printf("请输入学生升学考试成绩 : ");
	scanf("%d", &pstu->score);
	pstu->next = NULL;

	return pstu;
}

//4.把学生信息节点加入到链表中
int AddStudent(PSTUDENT pstu)
{
	PSTUDENT ps = &g_head;
	if (!pstu){
		return 0;
	}

	//判断该学生信息是否存在
	if (GetPrevAddr(pstu->num)){
		printf("学号为%d的学生信息已存在。\n", pstu->num);
		free(pstu);
		return 0;
	}

	while (ps->next){
		ps = ps->next;
	}

	//新节点加入到链表最后端
	ps->next = pstu;
	pstu->next = NULL;
	return 1;
}

//9.获取用户选择
int Question(const char *pstr)
{
	char answer;
	printf("%s请选择(y / n):",pstr);
	while (1 != scanf("%c", &answer) || (answer != 'y' && answer != 'n')){
		printf("输入有误，%s 请重新输入(y / n) : ", pstr);
		fflush(stdin);
	}
	
	if ('y' == answer){
		return 1;
	}else{
		return 0;
	}
}

//10.获取用户输入学生的编号
int GetInputNum()
{
	int num;
	printf("请输入学生编号 : ");
	while (1 != (scanf("d", &num))){
		printf("编号输入有误，请重新输入: ");
		fflush(stdin);
	}

	return num;
}

//显示某个学生信息
void ShowStudent(int num)
{
	PSTUDENT pstu = GetPrevAddr(num);

	printf("---------------------------------------------\n");
	printf("  编号	姓名		性别	年龄	总分\n");
	printf("---------------------------------------------\n");
	
	printf("  %-8d	",pstu->next->num);
	printf("%-20s", pstu->next->name);
	printf("%c", pstu->next->sex);
	printf("%4d", pstu->next->age);
	printf("%4d", pstu->next->score);

}

//6.显示所有学生信息
void ShowAll()
{
	PSTUDENT pstu = &g_head;
	printf("---------------------------------------------\n");
	printf("  编号	姓名		性别	年龄	总分\n");
	printf("---------------------------------------------\n");
	
	while (pstu->next){
		printf("  %-8d	",pstu->next->num);
		printf("%-20s", pstu->next->name);
		printf("%c", pstu->next->sex);
		printf("%4d", pstu->next->age);
		printf("%4d", pstu->next->score);

		pstu = pstu->next;
	}
	printf("\n");
	printf("---------------------------------------------\n");
}

//7.显示信息数量
int ShowStudentCount()
{
	int count = 0;
	PSTUDENT pstu = &g_head;
	while (pstu->next){
		++count;
		pstu = pstu->next;
	}

	printf("当前共有%d位学生信息\n", count);
	return count;
}

//8.根据学生学号修改学生信息
void UpdateStudent(int num)
{
	PSTUDENT pstu = GetPrevAddr(num);
	int choose;
	if (!pstu){
		printf("没有对应编号%d学生信息\n", num);
		return 0;
	}

	//将要修改的学员指针改为指向自己的
	pstu = pstu->next;

	printf("当前学生的姓名为%s,", pstu->name);
	if (Question("确定要修改吗?")){
		printf("请输入学生姓名 : ");
		scanf("%20s", pstu->name);
	}

	printf("当前学生性别为 %c,", pstu->sex);
	if (Question("确定要修改吗?")){
		printf("请重新输入性别 : ");
		while (1 != scanf("%d", &choose)){
			printf("性别输入有误，请重新输入 : ");
			fflush(stdin);
		}
	}

	
	printf("当前学生年龄为 %d,", pstu->age);
	if (Question("确定要修改吗?")){
		printf("请重新输入年龄 : ");
		while (1 != scanf("%d", &pstu->age) || choose < 10 || choose > 35){
			printf("年龄输入有误，请重新输入(10 ~ 35) : ");
			fflush(stdin);
			}
		}	

	printf("当前学生的总分为%d,", pstu->score);
	if (Question("确定要修改吗?")){
		printf("请输入学生总分 : ");
		scanf("%d", &pstu->score);
	}

	printf("学生信息修改完毕\n");
}



//11.按照学号删除学生信息
void DeleteStudent(int num)
{
	PSTUDENT pstu, ptmp;
	if (pstu = GetPrevAddr(num)){
		if (!Question("确定要删除该学生吗?")){
			return ;
		}

		ptmp = pstu->next;
		pstu->next = ptmp->next;
		free(ptmp);

		printf("删除了编号 %d 的学生信息\n", num);
	}else{
		printf("没有找到编号 %d 的学生信息\n", num);
	}
}

//12.删除所有学生信息
void DeleteAll()
{
	PSTUDENT pstu = g_head.next;
	PSTUDENT ptmp;
	int count = 0;
	if (!Question("确定要删除所有学生信息吗?\n")){
		return;
	}

	while (pstu){
		ptmp = pstu;
		pstu = pstu->next;
		free(ptmp);

		++count;
	}

	g_head.next = NULL;

	printf("共删除 %d 位学生\n", count);
}

//13.把学生信息保存到文本中
void SaveToFile()
{
	FILE *fp = fopen(FILENAME, "wb");
	PSTUDENT pstu = &g_head;
	
	int i = 0, count = ShowStudentCount();

	if (!fp){
		printf("打开文件失败\n");
		return;
	}

	if (!Question("确定要保存学生信息到文件中吗?\n")){
		fclose(fp);
		return ;
	}

	fwrite(&count, 1, sizeof(count), fp);

	while (pstu->next){
		fwrite(pstu->next, 1, sizeof(STUDENT), fp);
		++i;
		pstu = pstu->next;
	}

	fclose(fp);
	if (i == count){
		printf("成功写入%d条学生信息\n", count);
	}else{
		printf("应写入%d条学生信息, 实际写入%d条学生信息\n", count, i);
	}
}

//14.从文本中读取学生信息
void LoadFromFile()
{
	int i, count = 0, repeat = 0;

	FILE *fp;
	PSTUDENT pstu;
	printf("提示：从文件中读取学生信息会询问是否清空当前学生信息\n");
	if ((fp = fopen(FILENAME, "rb")) == NULL){
		printf("文件还没有创建，无法读取到信息\n");
		return ;
	}

	DeleteAll();
	fread(&count, 1, sizeof(count), fp);

	for (i=0; i<count; ++i){
		pstu = (PSTUDENT)malloc(sizeof(STUDENT));
		fread(pstu, 1, sizeof(STUDENT), fp);
		if (!AddStudent(pstu)){
			++repeat;//保持有多少个和当前链表重复的学生信息
		}
	}

	fclose(fp);
	printf("文件读取完毕，新增学生信息%d 条\n",count-repeat);
}


