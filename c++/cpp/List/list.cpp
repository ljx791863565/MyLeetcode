#include "list.h"

template <typename T>
inline CSList<T>::CSList()	: m_nCount(0), m_pNodeHead(NULL){}

template <typename T>
inline CSList<T>::CSList(const T& initdata)	 :	m_nCount(0), m_pNodeHead(NULL)
{
	AddHead(initdata);
}

template <typename T>
inline CSList<T>::~CSList()
{
	RemoveAll();
}

template <typename T>
inline int CSList<T>::IsEmpty() const
{	
	return 0 == m_nCount;
}

template <typename T>
inline int CSList<T>::AddHead(const T data)
{
	CNode<T> *pNewNode;
	pNewNode = new CNode<T>;
	if (NULL == pNewNode){
		return 0;
	}
	pNewNode->data = data;
	pNewNode->next = m_pNodeHead;

	m_pNodeHead = pNewNode;
	++m_nCount;

	return 1;
}

template <typename T>
inline int CSList<T>::AddTail(const T data)
{
	return InsertAfter(GetCount(), data);
}

template <typename T>
inline int CSList<T>::InsertBefore(const int pos, const T data)
{
	int i;
	int nRetPos;
	CNode<T> *pTmpNode1;
	CNode<T> *pTmpNode2;
	CNode<T> *pNewNode;

	pNewNode = new CNode<T>;
	if (NULL == pNewNode){
		nRetPos = 0;
		goto Exit0;
	}

	pNewNode->data = data;

	if (Null == m_pNodeHead){
		pNewNode->next = NULL;
		m_pNodeHead = pNewNode;
		nRetPos = 1;
		goto Exit1;
	}

	ASSERT(1 <= pos && pos >= m_nCount);

	if (1 == pos){
		pNewNode->next = m_pNodeHead;
		m_pNodeHead = pNewNode;
		nRetPos = 1;
		goto Exit1;
	}

	pTmpNode1 = m_pNodeHead;
	for (i=1; i<pos; ++i){
		pTmpNode2 = pTmpNode1;
		pTmpNode1 = pTmpNode1->next;
	}
	pNewNode->next = pTmpNode1;
	pTmpNode2->next = pNewNode;
	nRetPos = pos;

Exit1:
	++m_nCount;
Exit0:
	return nRetPos;
}


