#include <iostream>
#include "DoublyLinkedListWithGuard.h"

using namespace std;

CDoublyLinkedListWithGuard::CDoublyLinkedListWithGuard()
{
	m_pHead->pNext = m_pTail;
	m_pTail->pPrev = m_pHead;
}


CDoublyLinkedListWithGuard::CDoublyLinkedListWithGuard(const CDoublyLinkedListWithGuard& _doublyLinkedListWithGuard)
{

}


CDoublyLinkedListWithGuard& CDoublyLinkedListWithGuard::operator=(const CDoublyLinkedListWithGuard& _doublyLinkedListWithGuard)
{
	return *this;
}


CDoublyLinkedListWithGuard::~CDoublyLinkedListWithGuard()
{

}


bool CDoublyLinkedListWithGuard::insertHead(const int& val)
{
	stDoubNode* p_doubNode = new stDoubNode(val);
	return insertHead(p_doubNode);
}


bool CDoublyLinkedListWithGuard::insertHead(stDoubNode* pNewNode)
{
	if (m_pHead == nullptr || pNewNode == nullptr)
		return false;
	/*if (m_pHead->pNext == nullptr)
	{
		m_pHead->pNext = pNewNode;
		pNewNode->pPrev = m_pHead;
	}
	else*/
	{
		m_pHead->pNext->pPrev = pNewNode;
		pNewNode->pNext = m_pHead->pNext;
		pNewNode->pPrev = m_pHead;
		m_pHead->pNext = pNewNode;
	}
	return true;
}


bool CDoublyLinkedListWithGuard::insertTail(const int& val)
{
	stDoubNode* p_doubNode = new stDoubNode(val);
	return insertTail(p_doubNode);
}


bool CDoublyLinkedListWithGuard::insertTail(stDoubNode* pNewNode)
{
	if (m_pHead == nullptr || pNewNode == nullptr)
		return false;

	
	stDoubNode* tmp = m_pHead->pNext;
	while (tmp->pNext != nullptr)
		tmp = tmp->pNext;
	pNewNode->pPrev = tmp->pPrev;
	pNewNode->pNext = tmp;
	tmp->pPrev->pNext = pNewNode;
}


bool CDoublyLinkedListWithGuard::insertBefore(stDoubNode* p, const int& val)
{
	stDoubNode* p_doubNode = new stDoubNode(val);
	return insertBefore(p, p_doubNode);
}


bool CDoublyLinkedListWithGuard::insertBefore(stDoubNode* p, stDoubNode* pNewNode)
{
	if (p == nullptr || pNewNode == nullptr)
		return false;
	stDoubNode* prev = p->pPrev;
	pNewNode->pNext = p;
	pNewNode->pPrev = prev;
	prev->pNext = pNewNode;
	p->pPrev = pNewNode;
	return true;
}


bool CDoublyLinkedListWithGuard::insertAfter(stDoubNode* p, const int& val)
{
	stDoubNode* p_doubNode = new stDoubNode(val);
	return insertAfter(p, p_doubNode);
}


bool CDoublyLinkedListWithGuard::insertAfter(stDoubNode* p, stDoubNode* pNewNode)
{
	if (p == nullptr || pNewNode == nullptr)
		return false;
	stDoubNode* next = p->pNext;

	pNewNode->pNext = next;
	pNewNode->pPrev = p;
	p->pNext = pNewNode;
	next->pPrev = pNewNode;
	
	return true;
}


bool CDoublyLinkedListWithGuard::deleteNode(const int& val)
{
	if (m_pHead == nullptr)
		return false;
	stDoubNode* tmp = m_pHead->pNext;
	while (tmp != nullptr && tmp->data != val)
		tmp = tmp->pNext;
	if (tmp == nullptr)
		return false;
	return deleteNode(tmp);
}


bool CDoublyLinkedListWithGuard::deleteNode(const stDoubNode* p)
{
	if (p == nullptr)
		return false;
	stDoubNode* prev = p->pPrev;
	stDoubNode* next = p->pNext;
	delete p;
	prev->pNext == next;
	if (next != nullptr)
	{
		next->pPrev = prev;
	}
	return true;
}


stDoubNode* CDoublyLinkedListWithGuard::findByVal(const int& val)
{
	if (m_pHead == nullptr)
		return nullptr;
	stDoubNode* tmp = m_pHead->pNext;
	while (tmp != nullptr && tmp->data != val)
		tmp = tmp->pNext;
	return tmp;
}


stDoubNode* CDoublyLinkedListWithGuard::findByIdx(const int& idx)
{
	if (m_pHead == nullptr)
		return nullptr;
	stDoubNode* tmp = m_pHead->pNext;
	int count = 0;
	while (tmp != nullptr && count != idx)
	{
		tmp = tmp->pNext;
		count++;
	}
	return tmp;
}


void CDoublyLinkedListWithGuard::printLinkedList() const
{
	if (m_pHead == nullptr)
		return;
	stDoubNode* tmp = m_pHead->pNext;
	while (tmp != nullptr)
	{
		cout << tmp->data << endl;
		tmp = tmp->pNext;
	}
	return;
}