#ifndef __BOOK_SYSTEM__H__
#define __BOOK_SYSTEM__H__

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
const int Maxr = 100;
const int Maxb = 100;
const int Maxbor = 5;

//读者类
class Reader
{
private:
	int tag;
	int no;
	char name[10];
	int borbook[Maxbor];
public:
	Reader(){}
	char * GetName()
	{
		return name;
	}
	int GetTag()
	{
		return tag;
	}
	int GetNo()
	{
		return no;
	}
	void SetName(char *namestr)
	{
		strcpy(name, namestr);
	}
	void DelBook()
	{
		tag = 1;
	}
	void AddReader(int n, char *namestr)
	{
		tag = 0;
		no = n;
		strcpy(name, namestr);
		for (int i=0; i<Maxbor; ++i){
			borbook[i] = 0;
		}
	}
	
	//借书方法
	void BorrowBook(int bookid)
	{
		for (int i=0; i<Maxbor; ++i){
			if (borbook[i] = 0){
				borbook[i] = bookid;
				return;
			}
		}
	}
	//还书方法
	int RetBook(int bookid)
	{
		for (int i=0; i<Maxbor; ++i){
			if (borbook[i] == bookid){
				borbook[i] = 0;
				return 1;
			}
		}
		return 0;
	}

	void DisPlay()
	{
		cout << setw(5) << no << setw(10) << name << "借书编号：[";
		for (int i=0; i<Maxbor; ++i){
			if (borbook[i] != 0){
				cout << borbook[i] << "|";
			}
			cout << "]" << endl;
		}
	}
};

//读者库类
class RDatabase
{
private:
	int top;
	Reader read[Maxr];
public:
	RDatabase()
	{
		Reader s;
		top = -1;
		fstream file("reader.txt", ios::in);

		while (1)
		{
			file.read((char *)&s, sizeof(s));
			if (!file){
				break;
			}
			top++;
			read[top] = s;
		}
		file.close();
	}

	void clear()
	{
		top = -1;
	}
	Reader *query(int readerid)
	{
		for (int i=0; i<=top; ++i){
			if ((read[i].GetNo() == readerid) && (read[i].GetTag() == 0)){
				return &read[i];
			}
		}
		return NULL;
	}

	int AddReader(int n, char *namestr)
	{
		Reader *p = query(n);
		if (p == NULL){
			top ++;
			read[top].AddReader(n, namestr);
			return 1;
		}
		return 0;
	}
	void DisPlay()
	{
		for (int i=0; i<=top; ++i){
			read[i].DisPlay();
		}
	}
	void readerdata();
	~RDatabase()
	{
		fstream file("reader.txt", ios::out);
		for (int i=0; i<=top; ++i){
			if (read[i].GetTag() == 0){
				file.write((char *)&read[i], sizeof(read[i]));
			}
			file.close();
		}
	}
};
//读者维护
void RDatabase::readerdata()
{
	char choice;
	char name[20];
	int readerid;
	Reader *r;
	while (choice != '0')
	{
		printf("\n\n\t\t\t 读者维护");
		printf("\n\t\t\t1 新增\n");
		printf("\n\t\t\t2 更改\n");
		printf("\n\t\t\t3 删除\n");
		printf("\n\t\t\t4 查找\n");
		printf("\n\t\t\t5 显示\n");
		printf("\n\t\t\t6 全删\n");
		printf("\n\t\t\t0 退出\n\n\n\n");
		cin >> choice;
		switch (choice)
		{
			case '1':
				cout << "输入读者学号:";
				cin >> readerid;
				cout << "输入读者姓名:";
				cin >> name;
				AddReader(readerid, name);
				break;
			case '2':
				cout << "输入读者学号:";
				cin >> readerid;
				r = query(readerid);
				if (r == NULL){
					cout << "该读者不存在" << endl;
					break;
				}
				cout << "输入新的姓名:";
				cin >> name;
				r->SetName(name);
				break;
			case '3':
				cout << "输入读者学号:";
				cin >> readerid;
				r = query(readerid);
				if (r == NULL){
					cout << "该读者不存在" << endl;
					break;
				}
				r->DelBook();
				break;
			case '4':
				cout << "输入读者学号:";
				cin >> readerid;
				r = query(readerid);
				if (r == NULL){
					cout << "该读者不存在" << endl;
					break;
				}
				DisPlay();
				break;
			case '5':
				DisPlay();
				break;
			case '6':
				clear();
			default:
				cout << "输入有误，请重新输入 " << endl;
				break;
		}
	}
}

//图书类
class Book
{
private:
	int price;
	char author[10];
	int tag;
	int no;
	char name[20];
	int onshelf;
public:
	Book(){}
	char *GetName()
	{
		return name;
	}
	int GetNo()
	{
		return no;
	}
	int GetTag()
	{
		return tag;
	}
	char *GetAuthor()
	{
		return author;
	}
	int GetPrice()
	{
		return price;
	}	
	void SetName(char *namestr)
	{
		strcpy(name, namestr);
	}
	void SetAuthor(char *authorstr)
	{
		strcpy(author, authorstr);
	}
	void DelBook()
	{
		tag = 1;
	}
	void AddBook(int n, char *namestr, char *authorstr, int pr)
	{
		tag = 0;
		no = n;
		price = pr;
		strcpy(author, authorstr);
		strcpy(name, namestr);
		onshelf = 1;
	}
	int BorrowBook()
	{
		if (onshelf == 1){
			onshelf = 0;
			return 1;
		}
		return 0;
	}
	void RetBook()
	{
		onshelf = 1;
	}
	void DisPlay()
	{
		cout << setw(6) << "图书编号:" << no << setw(18) << "图书名:" << name 
		   << setw(10) << "作者名" << author << setw(18) << "图书单价:" << price 
			<<setw(10) << (onshelf == 1 ? "在架" : "已借") << endl;	   
	}
};

//图书库类
class BDatabase
{
private:
	int top;
	Book book[Maxb];
public:
	BDatabase()
	{
		Book b;
		top = 1;
		fstream file("book.txt", ios::in);
		while (1){
			file.read((char *)&b, sizeof(b));
			if (!file){
				break;
			}
			top++;
			book[top] = b;
		}
		file.close();
	}
	void clear()
	{
		top = 1;

	}

	Book *query(int bookid)
	{
		for (int i=0; i<= top; ++i){
			if (book[i].GetNo() == bookid && book[i].GetTag() == 0){
				return &book[i];
			}
		}
		return NULL;
	}

	void bookdata();

	int AddBook(int n, char *namestr, char *authorstr, int pr)
	{
		Book *p = query(n);
		if (NULL == p){
			top ++;
			book[top].AddBook(n, namestr, authorstr, pr);
			return 1;
		}
		return 0;
	}
	void DisPlay()
	{
		for (int i=0; i<=top; ++i){
			if (book[i].GetTag() == 0){
				book[i].DisPlay();
			}
		}
	}
	~BDatabase()
	{
		fstream file("book.txt", ios::out);
		for (int i=0; i<=top; ++i){
			if (book[i].GetTag() == 0){
				file.write((char *)&book[i], sizeof(book[i]));
			}
		}
		file.close();
	}
};
//图书维护
void BDatabase::bookdata()
{
	char choice;
	char bauthor[10];
	int bprice;
	char bname[40];
	int bookid;
	Book *b;
	while (choice != '0'){
		printf("\n\n\t\t\t 图书维护");
		printf("\n\t\t\t1 新增\n");
		printf("\n\t\t\t2 更改\n");
		printf("\n\t\t\t3 删除\n");
		printf("\n\t\t\t4 查找\n");
		printf("\n\t\t\t5 显示\n");
		printf("\n\t\t\t6 全删\n");
		printf("\n\t\t\t0 退出\n\n\n\n");
		cin >> choice;
		switch (choice)
		{
			case '1':
				cout << "输入图书编号 :" << endl;
				cin >> bookid;
				cout << "输入图书书名 :" << endl;
				cin >> bname;
				cout << "输入作者名 :"  << endl;
				cin >> bauthor;
				cout << "输入价格 :" << endl;
				cin >> bprice;
				AddBook(bookid, bname, bauthor, bprice);
				break;
			case '2':
				cout << "输入图书编号 :" << endl;
				cin >> bookid;
				b = query(bookid);
				if (b == NULL){
					cout << "该图书不存在" << endl;
					break;
				}
				cout << "输入新的书名 :" << endl;
				cin >> bname;
				b->SetName(bname);
				break;
			case '3':
				cout << "输入图书编号 :" << endl;
				cin >> bookid;
				b = query(bookid);
				if (NULL == b){
					cout << "该图书不存在 " << endl;
					break;
				}
				b->DelBook();
				break;
			case '4':
				cout << "输入图书编号 :" << endl;
				cin >> bookid;
				b = query(bookid);
				if (NULL == b){
					cout << "该图书不存在 " << endl;
					break;
				}
				b->DisPlay();
				break;
			case '5':
				DisPlay();
				break;
			case '6':
				clear();
				break;
			default:
				cout << "输入有误，请重新输入 " << endl;
				break;
		}
	}
}


#endif //__BOOK_SYSTEM__H__
