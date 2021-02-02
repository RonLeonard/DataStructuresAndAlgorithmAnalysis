#include "SingleLinkedList.h"



CSingleLinkedList::CSingleLinkedList() : m_pHead(nullptr)
{

}


CSingleLinkedList::CSingleLinkedList(const CSingleLinkedList& singleLinkList)
{

}



CSingleLinkedList::~CSingleLinkedList()
{

}



CSingleLinkedList& CSingleLinkedList::operator=(const CSingleLinkedList& singleLinkList)
{

}


bool CSingleLinkedList::insertHead(const int val)
{
	stNode* pNode = new stNode(val, nullptr);
	return insertHead(pNode);
}


bool CSingleLinkedList::insertHead(stNode* pNode)
{
	if (pNode == nullptr)
		return false;
	if (m_pHead == nullptr)
	{
		m_pHead = pNode;
	}
	else
	{
		pNode->pNext = m_pHead;
		m_pHead = pNode;
	}
	return true;
}


bool CSingleLinkedList::insertTail(const int val)
{
	stNode* pNode = new stNode(val, nullptr);
	return insertTail(pNode);
}


bool CSingleLinkedList::insertTail(stNode* pNode)
{
	if (pNode == nullptr)
		return false;
	if (m_pHead == nullptr)
	{
		m_pHead = pNode;
	}
	else
	{
		stNode* tmp = m_pHead;
		while (tmp->pNext != nullptr)
		{
			tmp = tmp->pNext;
		}
		tmp->pNext = pNode;
	}
	return true;
}


bool CSingleLinkedList::insertBefore(stNode* p, const int val)
{
	stNode* pNode = new stNode(val, nullptr);
	return insertBefore(p, pNode);
}


bool CSingleLinkedList::insertBefore(stNode* p, stNode* pNewNode)
{
	if (pNewNode == nullptr)
		return false;

	if (p == m_pHead)
		return insertHead(pNewNode);
	else
	{
		stNode* tmp = m_pHead;
		while (tmp != nullptr && tmp->pNext != p)
		{
			tmp = tmp->pNext;
		}
		if (tmp == nullptr)
			return false;
		pNewNode->pNext = tmp->pNext;
		tmp->pNext = pNewNode;
		return true;
	}
}


bool CSingleLinkedList::insertAfter(stNode* p, const int val)
{
	stNode* pNode = new stNode(val, nullptr);
	return insertAfter(p, pNode);
}


bool CSingleLinkedList::insertAfter(stNode* p, stNode* pNewNode)
{
	if (p == nullptr)
		return false;
	pNewNode->pNext = p->pNext;
	p->pNext = pNewNode;
	return true;	
}


bool CSingleLinkedList::deleteNode(const int val)
{
	if (m_pHead == nullptr)
		return false;
	stNode* p = m_pHead;
	stNode* q = nullptr;
	while (p != nullptr && p->data != val)
	{
		q = p;
		p = p->pNext;
	}
	if (p == nullptr)
		return false;
	if (q == nullptr)
	{
		m_pHead = m_pHead->pNext;
		delete p;
		return true;
	}
	q->pNext = q->pNext->pNext;
	delete p;
	return true;
}


bool CSingleLinkedList::deleteNode(stNode* pNewNode)
{
	if (pNewNode == nullptr || m_pHead == nullptr)
		return false;

	stNode* tmp = m_pHead;
	if (tmp == pNewNode)
	{
		delete tmp;
		m_pHead = m_pHead->pNext;
		return true;
	}

	while (tmp != nullptr && tmp->pNext != pNewNode)
	{
		tmp = tmp->pNext;
	}
	if (tmp == nullptr)
		return false;

	stNode* tmp2 = tmp->pNext;
	tmp->pNext = tmp->pNext->pNext;
	delete tmp2;
}



uint CSingleLinkedList::getCount(stNode* pHead) const
{
	if (pHead == nullptr) return 0;
	else
	{
		uint count = 0;
		stNode* tmp = pHead;
		while (tmp != nullptr)
		{
			count++;
			tmp = tmp->pNext;
		}
		return count;
	}
}