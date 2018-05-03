#include "bookSystem.h"
int main()
{
	char choice;
	int bookid, readerid;
	RDatabase ReaderDB;
	Reader *r;
	BDatabase BookDB;
	Book *b;
	
	while (choice != '0'){
		printf("\n\n\t\t\t图书管理系统");
		printf("\n\t\t\t1 借书");
		printf("\n\t\t\t2 还书");
		printf("\n\t\t\t3 图书维护");
		printf("\n\t\t\t4 读者维护");
		printf("\n\t\t\t0 离开\n\n\n");
		cin >> choice;
		switch (choice){
			case '1':
				cout << "借书" << endl;
			   cout <<	"读者学号 : ";
				cin >> readerid;
				cout << "图书编号 :";
				cin >> bookid;
				r = ReaderDB.query(readerid);
				if (NULL == r){
					cout << "不存在该读者，不能借书" << endl;
					break;
				}
				b = BookDB.query(bookid);
				if (NULL == b){
					cout << "不存在该图书，不能借书" << endl;
					break;
				}
				if (b->BorrowBook() == 0){
					cout << "该图书已借出,不能借书" << endl;
					break;
				}
				r->BorrowBook(b->GetNo());
				break;
			case '2':
				cout << "还书 "<< endl;
			   	cout << "读者学号 ：" << endl;
				cin >> readerid;
				cout << "图书编号 :";
				cin >> bookid;
				r = ReaderDB.query(readerid);
				if (NULL == r){
					cout << "不存在该读者，不能借书" << endl;
					break;
				}
				b = BookDB.query(bookid);
				if (NULL == b){
					cout << "不存在该图书，不能借书" << endl;
					break;
				}
				b->RetBook();
				r->RetBook(b->GetNo());
				break;
			case '3':
				BookDB.bookdata();
				break;
			case '4':
				ReaderDB.readerdata();
				break;
			case '0':
				break;
			default:
				cout << "输入错误，请重新输入" << endl;
				break;
		}
	}
	return 0;
}
