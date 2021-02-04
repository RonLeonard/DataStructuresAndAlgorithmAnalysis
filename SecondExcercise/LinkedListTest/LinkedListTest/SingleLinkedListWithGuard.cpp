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
	return 0;
}


bool CSingleLinkedListWithGuard::insertTail(const int data)
{

}