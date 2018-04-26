#include "list.h"

using namespace std;
int main()
{
	
	CSList<int> slist;	
	slist.InsertAfter(slist.InsertAfter(slist.AddHead(1), 2), 3);
	slist.InsertAfter(slist.InsertAfter(slist.GetCount(),4), 5);
	slist.InsertAfter(slist.GetCount(), 6);
	slist.AddTail(10);
	slist.InsertBefore(slist.InsertBefore(slist.GetCount(), 7), 8);
	
	int i, nCount;
	nCount = slist.GetCount();
	
	for (i=0; i<nCount; ++i){
		cout << slist.GetAt(i+1) << " " ;
	}	
	cout << endl;
	
	return 0;
}
