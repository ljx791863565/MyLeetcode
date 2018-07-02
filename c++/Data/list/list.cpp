#include "list.h"

template <typename T>
inline CSList<T>::CSList():
	m_nCount(0), m_pNodeHead(NULL)
{

}

template <typename T>
inline CSList<T>::CSList(const T &initdata):
	m_nCount(0), m_pNodeHead(NULL)
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
	CNode<T> *pNewNode = new CNode<T>;
	if (NULL == pNewNode)
		return 0;

	pNewNode->data = data;
	pNewNode->next = m_pNodeHead;

	m_pNodeHead = pNewNode;
	++m_nCount;

	return 1;
}

template <typename T>
inline int AddTail(const T data)
{
	InsertAfter(GetCount(), data);
}

template <typename T>
inline int CSList<T>::InsertAfter(const int pos, const T data)
{
	int i;
	int nRetPos;
	CNode<T> *pTmpNode;
	CNode<T> *pNewNode = new CNode<T>;

	if (NULL == pNewNode){
		nRetPos = 0;
		return nRetPos;
	}
	pNewNode->data = data;
	if (NULL == m_pNodeHead){
		pNewNode->next = NULL;
		m_pNodeHead = pNewNode;
		nRetPos = 1;
		++m_nCount;
	}
	assert(1<=nRetPos && pos <= m_nCount);

	pTmpNode = m_pNodeHead;
	for (i=0; i<pos; ++i){
		pTmpNode = pTmpNode->next;
	}
	pNewNode->next = pTmpNode->next;
	pTmpNode->next = pNewNode;

	nRetPos = pos + 1;
}

template <typename T>
inline int CSList<T>::InsertBefore(const int pos, const T data)
{
	int i;
	int nRetPos;
	CNode<T> *pTmpNode1, *pTmpNode2;

	CNode<T> *pNewNode = new CNode<T>;
	if (NULL == pNewNode){
		nRetPos = 0;
		return nRetPos;
	}
	pNewNode->data = data;
	assert(1<=nRetPos && pos <= m_nCount);
	if (1 == pos){
		pNewNode->next = m_pNodeHead;
		m_pNodeHead = pNewNode;
		nRetPos = 1;
		++m_nCount;
	}
	pTmpNode1 = m_pNodeHead;
	for (i=1; i<pos; ++i){
		pTmpNode2 = pTmpNode1;
		pTmpNode1 = pTmpNode1->next;
	}
	pNewNode->next = pTmpNode1;
	pTmpNode2->next = pNewNode;
	nRetPos = pos;
}

template <typename T>
inline int CSList<T>::GetCount() const
{
	return m_nCount;
}
