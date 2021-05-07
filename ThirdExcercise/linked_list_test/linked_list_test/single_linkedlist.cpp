#include "single_linkedlist.h"

CSingleLinkedList::CSingleLinkedList()
{
	head = new StNode();
}


CSingleLinkedList::~CSingleLinkedList()
{
	while (head != nullptr)
	{
		StNode* tmp = head;
		head = head->next;
		delete tmp;
	}
}


StNode* CSingleLinkedList::findVal(const int& val)
{
	if (head == nullptr)
		return nullptr;
	StNode* tmp = head->next;
	while (tmp != nullptr)
	{
		if (tmp->data == val)
			return tmp;
		else
			tmp = tmp->next;
	}
	return nullptr;
}


bool CSingleLinkedList::delVal(const int& val)
{
	if (head == nullptr)
		return false;
	StNode *prev = head;
	StNode *tmp = head->next;
	while (tmp != nullptr)
	{
		if (tmp->data == val)
		{
			prev->next = tmp->next;
			delete tmp;
			return true;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return false;
}
bool CSingleLinkedList::delNode(const StNode* pNode);
bool CSingleLinkedList::insertBefore(const StNode* pNode, const int& val);
bool CSingleLinkedList::insertAfter(const StNode* pNode, const int& val);
bool CSingleLinkedList::insertHead(const int& val);
bool CSingleLinkedList::insertTail(const int& val);