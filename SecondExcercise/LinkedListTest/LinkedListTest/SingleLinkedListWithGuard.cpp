#include "SingleLinkedListWithGuard.h"


CSingleLinkedListWithGuard::CSingleLinkedListWithGuard()
{

}


//copy constructor
//CSingleLinkedListWithGuard::CSingleLinkedListWithGuard(const CSingleLinkedListWithGuard& p)
//{
//
//}


CSingleLinkedListWithGuard::~CSingleLinkedListWithGuard()
{
	stNode* q = nullptr;
	while (m_pHead != nullptr)
	{
		q = m_pHead;
		m_pHead = m_pHead->pNext;
		delete q;
	}
}


//copy assignment operator
//CSingleLinkedListWithGuard& CSingleLinkedListWithGuard::operator=(const CSingleLinkedListWithGuard& p)
//{
//
//}


bool CSingleLinkedListWithGuard::insertHead(const int data)
{
	stNode* pNode = new stNode(data, nullptr);
	return insertHead(pNode);
}

bool CSingleLinkedListWithGuard::insertHead(stNode* pNode)
{
	if (pNode == nullptr || m_pHead == nullptr) return false;
	pNode->pNext = m_pHead->pNext;
	m_pHead->pNext = pNode;
	return true;
}


bool CSingleLinkedListWithGuard::insertTail(const int data)
{
	stNode* pNode = new stNode(data, nullptr);
	return insertTail(pNode);
}


bool CSingleLinkedListWithGuard::insertTail(stNode* pNode)
{
	if (pNode == nullptr || m_pHead == nullptr) return false;
	stNode* tmp = m_pHead;
	while (tmp->pNext != nullptr)
	{
		tmp = tmp->pNext;
	}
	pNode->pNext = tmp->pNext;
	tmp->pNext = pNode;
	return true;
}


bool CSingleLinkedListWithGuard::insertBefore(stNode* p, const int data)
{
	stNode* pNode = new stNode(data, nullptr);
	return insertBefore(p, pNode);
}


bool CSingleLinkedListWithGuard::insertBefore(stNode* p, stNode* pNewNode)
{
	if (p == nullptr || pNewNode == nullptr || m_pHead == nullptr) return false;
	stNode* tmp = m_pHead;
	while (tmp->pNext != nullptr && tmp->pNext != p)
	{
		tmp = tmp->pNext;
	}
	if (tmp->pNext == nullptr) return false;
	pNewNode->pNext = p;
	tmp->pNext = pNewNode;
	return true;
}


bool CSingleLinkedListWithGuard::insertAfter(stNode* p, const int data)
{
	stNode* pNode = new stNode(data, nullptr);
	return insertAfter(p, pNode);
}


bool CSingleLinkedListWithGuard::insertAfter(stNode* p, stNode* pNewNode)
{
	if (p == nullptr || pNewNode == nullptr) return false;
	pNewNode->pNext = p->pNext;
	p->pNext = pNewNode;
	return true;
}


bool CSingleLinkedListWithGuard::deleteNode(const int val)
{
	if (m_pHead == nullptr) false;
	stNode* tmp = m_pHead;

	while (tmp->pNext != nullptr && tmp->pNext->data != val)
	{
		tmp = tmp->pNext;
	}
	if (tmp->pNext == nullptr) return false;
	stNode* q = tmp->pNext;
	tmp->pNext = tmp->pNext->pNext;
	delete q;
	return true;
}


bool CSingleLinkedListWithGuard::deleteNode(stNode* pNode)
{
	if (pNode == nullptr || m_pHead == nullptr) false;
	stNode* tmp = m_pHead;
	while (tmp->pNext != nullptr && tmp->pNext != pNode)
	{
		tmp = tmp->pNext;
	}
	if (tmp->pNext == nullptr) return false;
	tmp->pNext = tmp->pNext->pNext;
	delete pNode;
	return true;
}


stNode* CSingleLinkedListWithGuard::findByVal(const int& val)
{
	if (m_pHead == nullptr) return nullptr;
	stNode* tmp = m_pHead->pNext;
	while (tmp != nullptr && tmp->data != val)
	{
		tmp = tmp->pNext;
	}
	return tmp;
}


stNode* CSingleLinkedListWithGuard::findByIndex(const unsigned int& idx)
{
	if (m_pHead == nullptr) return nullptr;
	unsigned int count = 0;
	stNode* tmp = m_pHead->pNext;
	while (tmp != nullptr && count != idx)
	{
		tmp = tmp->pNext;
		count++;
	}
	return tmp;
}


stNode* CSingleLinkedListWithGuard::getFirstNode()
{
	if (m_pHead == nullptr)
		return nullptr;
	else
		return m_pHead->pNext;
}

void CSingleLinkedListWithGuard::printLinkedList() const
{
	if (m_pHead == nullptr) return;
	stNode* tmp = m_pHead->pNext;
	while (tmp != nullptr)
	{
		printf("%d ", tmp->data);
		tmp = tmp->pNext;
	}
}