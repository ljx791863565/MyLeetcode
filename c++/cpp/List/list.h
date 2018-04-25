
#ifndef __LIST__H__
#define  __LIST__H__
#include <iostream>
#include <stdlib.h>
template <typename T>
class CNode 
{
public:
	CNode()	:data(0), next(NULL){}
	
	CNode(const T &initdata) : data(initdata),	next(NULL){}

	CNode(const T &initdata, CNode<T> *p) :	data(initdata), next(p){}
public:
	T data;		//数据域
	CNode<T> *next;	//指针域
};

template <typename T>
class CSLidt
{
public:
	CSList();
	CSList(const T &initdata);
	~CSList();

public:
	int		IsEmpty() const;
	int		GetCount() const;
	int		InsertBefore(const int pos, const T data);
	int		InsertAfter(const int pos, const T data);
	int		AddHead(const T data);
	int		AddTail(const T data);
	void	RemoveAt(const int pos);
	void	RemoveHead();
	void	RemoveTail();
	void	ReamoveAll();
	T&		GetTail();
	T		GetTail() const;
	T&		GetHead();
	T		GetHead() const;
	T&		GetAt(const int pos);
	T		GetAt(const int pos) const;
	void	SetAt(const int pos, T data);
	int		Find(const int data) const;

protected:
	int m_nCount;	//节点个数
	CNode<T> *m_pNodeHead;
};
#endif
