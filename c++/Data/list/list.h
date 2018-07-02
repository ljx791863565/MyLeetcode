#ifndef __LIST__H__
#define __LIST__H__
#include <iostream>
#include <assert.h>
template<typename T>
class CNode
{
public:
	T data;
	CNode<T> *next;
	CNode()	:data(0), next(NULL)
	{
	}
};

template<typename T>
class CSList
{
protected:
	int m_nCount;
	CNode<T> *m_pNodeHead;

public:
	CSList();
	CSList(const T &initdata);
	~CSList();
public:
	int IsEmpty() const;
	int GetCount() const;
	int InsertBefore(const int pos, const T data);
	int InsertAfter(const int pos, const T data);
	int AddHead(const T data);
	int AddTail(const T data);
	void RemoveAt(const int pos);
	void RemoveHead();
	void RemoveTail();
	void RemoveAll();
	T& GetTail();
	T GetTail() const;
	T& GetHead();
	T GetHead() const;
	T& GetAt(const int pos);
	T GetAt(const int pos) const;
	void SetAt(const int pos, T data);
	int Find(const T data) const;
};
#endif
