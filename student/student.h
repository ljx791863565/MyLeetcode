#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
class Student
{
public:
	int id;
	char name[20];
	int score;
	char sex;
	Student *next;
public:
	Student(){}
	~Student(){}
	int GetID()
	{
		return id;
	}
	char *GetName()
	{
		return name;
	}
	char GetSex()
	{
		return sex;
	}
	int GetScore()
	{
		return score;
	}
	void Input()
	{
		cout << "请输入学生学号:" << endl;
		cin >> id;
		cout << "请输入学生姓名:" << endl;
		cin >> name;
		cout << "请输入学生成绩:" << endl;
		cin >> score;
		cout << "请输入学生性别:" << endl;
		cin >> sex;
	}
	void Show()
	{
		cout << "学生信息 " << endl;
		cout << "学号 : " << id << endl;
		cout << "姓名 : " << name << endl;
		cout << "分数 : " << score << endl;
		cout << "性别 : " << sex << endl;
	}
};

class StudentMassage
{
public:
	StudentMassage();
	~StudentMassage();

	void ShowMenu();
	void Find();
	void Save();
	void ModifyItem();
	void RemoveItem();
	void Sort();
	void Swap(Student *p1, Student *p2);
	int ListCount();
	void DisPlay();
	void AddItem();
private:
	Student *Head, *End;
	ifstream *in;
	ofstream *out;
	Student *FindItem(char *name)
	{
		for (Student *p = Head; p->next != End; p = p->next){
			if (!strcmp(p->next->name, name)){
				return p;
			}
			return NULL;
		}
	}
	Student *FindID(int id)
	{
		for (Student *p = Head; p->next != End; p = p->next){
			if (p->id == id){
				return p;
			}
			return NULL;
		}
	}

};
StudentMassage::StudentMassage()
{
	Head = new Student;
	Head->next = new Student;
	End = Head->next;
	in->open("sort.txt");
	if (!in->eof()){
		cout << "系统初始化无数据，请先输入" << ednl;
	}else {
		while (!in->eof()){
			End->ReadFile(in);
			if (End->name[0] == '\0'){
				break;
			}
			End->next = new Student;
			End = End->next;
		}
		in->close();
		cout << "读取学生信息成功" << endl;
	}
}

StudentMassage::~StudentMassage()
{
	Save();
	for (Student *tmp; Head->next != End; ){
		tmp = Head->next;
		Head->next = Head->next->next;
		delete tmp;
	}
	delete Head;
	delete End;
}

void StudentMassage::ShowMenu()
{
	cout << "*******************************************************" << endl;
	cout << "***********		学生成绩管理系统		************" << endl;
	cout << "***********		1 增加学生成绩			************" << endl;
	cout << "***********		2 显示学生成绩			************" << endl;
	cout << "***********		3 学生成绩排序			************" << endl;
	cout << "***********		4 查找学生成绩			************" << endl;
	cout << "***********		5 删除学生成绩			************" << endl;
	cout << "***********		6 修改学生成绩			************" << endl;
	cout << "***********		0 退出					************" << endl;

	cout << "\n\t\t\n\t\t 请选择 :";
}

void StudentMassage::Find()
{
	char name[20];
	int id;
	Student *p = NULL;
	int choice;
	cout << "\n\t\t*****************************" << endl;
	cout << "\t\t 1 按学生姓名查找" << endl;
	cout << "\t\t 2 按学生学号查找" << endl;
	cout << endl;
	cout << endl;
	cout << "请选择" << endl;
	cin >> choice;

	switch (choice)
	{
		case 1:
			cout << "输入要查找的学生姓名" << endl;
			cin >> name;
			if (p = FindItem(name)){
				p->next->Show();
				sleep(3);
			}else{
				cout << "没有该学生信息" << endl;
				sleep(3);
			}
			break;
		case 2:
			cout << "输入要查找的学生学号" << endl;
			cin >> id;
			if (p = FindID(id)){
				p->next->Show();
				sleep(3);
			}else{
				cout << "没有该学生信息" << endl;
				sleep(3);
			}
			break;
		default :
			cout << "输入有误。重新输入" << endl;
			break;
	}
}

void StudentMassage::RemoveItem()
{
	int id;
	Student *p = NULL;
	Student *tmp = NULL;
	cout << "输入要删除的学生学号" << endl;
	cin >> id;
	if (p = FindID(id)){
		tmp = p->next;
		p->next = p->next->next;
		delete tmp;
		cout << "删除成功" << endl;
		sleep(3);
	}else {
		cout << "没有找到该学生，无法删除" << endl;
		sleep(3);
	}
}
//两个变量的数据域交换
void StudentMassage::Swap(Student *p1, Student *p2)
{
	Student *tmp = new Student;
	strcpy(tmp->name, p1->name);
	tmp->id = p1->id;
	tmp->sex = p1->sex;
	tmp->score = p1->score;

	strcpy(p1->name, p2->name);
	p1->id = p2->id;
	p1->sex = p2->sex;
	p1->score = p2->score;

	strcpy(p2->name, tmp->name);
	p2->id = tmp->id;
	p2->sex = tmp->sex;
	p2->score = tmp->score;
}

int StudentMassage::ListCount()
{
	if (!Head){
		return 0;
	}
	int count = 0;
	for (Student *p = Head->next; p != End; p = p->next){
		count++;
	}
	return count;
}

void StudentMassage::Sort()
{
	cout << "Sorting ..." << endl;
	Student *p = NULL;
	Student *q = NULL;
	Student *tmp = NULL;
	int n = StudentMassage::ListCount();
	if (n < 2){
		return ;
	}
	for (p = Head->next; p != End; p = p->next){
		for (q = p->next; q != End; q = q->next){
			if (p->score > q->score){
				StudentMassage::Swap(p, q);
			}
		}
	}
	cout << "Sort done" << endl;
	sleep(3);
	return ;
}
/*
void StudentMassage::Save()
{
	out->open("sort.txt");
	for (Student *p = Head->next; p != End; p = p->next){
		out << p->id << "\t" << p->name << "\t" << p->sex << "\t" << p->score << endl;
	}
	out->close();
}
*/
void StudentMassage::DisPlay()
{
	for (Student * p = Head->next; p != End; p = p->next){
		p->Show();
		sleep(3);
	}
}

#endif //__STUDENT_H__
