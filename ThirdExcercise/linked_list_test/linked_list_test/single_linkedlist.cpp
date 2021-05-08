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


bool CSingleLinkedList::delNode(const StNode* pNode)
{
	if (pNode == nullptr || head == nullptr)
		return false;
	StNode* prev = head;
	StNode* tmp = head->next;
	while (tmp != nullptr)
	{
		if (tmp == pNode)
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


bool CSingleLinkedList::insertBefore(const StNode* pNode, const int& val)
{
	if (pNode == nullptr || head == nullptr)
		return false;
	StNode* prev = head;
	StNode* tmp = head->next;
	while (tmp != nullptr)
	{
		if (tmp == pNode)
		{
			StNode* insNode = new StNode();
			insNode->data = val;
			insNode->next = prev->next;
			prev->next = insNode;
			return true;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return false;
}


bool CSingleLinkedList::insertAfter(const StNode* pNode, const int& val)
{
	if (pNode == nullptr || head == nullptr)
		return false;
	StNode* tmp = head->next;
	while (tmp != nullptr)
	{
		if (tmp == pNode)
		{
			StNode* insNode = new StNode();
			insNode->data = val;
			insNode->next = tmp->next;
			tmp->next = tmp;
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}


bool CSingleLinkedList::insertHead(const int& val)
{
	if (head == nullptr)
		return false;
	StNode* insNode = new StNode();
	insNode->data = val;
	insNode->next = head->next;
	head->next = insNode;
	return true;
}


bool CSingleLinkedList::insertTail(const int& val)
{
	if (head == nullptr)
		return false;
	StNode* insNode = new StNode();
	insNode->data = val;
	insNode->next = nullptr;
	StNode* tmp = head;
	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
	}
	tmp->next = insNode;
	return true;
}