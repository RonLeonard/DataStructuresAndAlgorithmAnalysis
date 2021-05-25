#include <stdio.h>
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


StNode* CSingleLinkedList::getHead()
{
	return head;
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
			tmp->next = insNode;
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


void CSingleLinkedList::inverseLinkedList()
{
	if (head == nullptr || head->next == nullptr)
		return;
	StNode* prev = head->next;
	StNode* curr = prev->next;
	StNode* next = nullptr;
	prev->next = nullptr;
	while (curr != nullptr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head->next = prev;
	return;
}


StNode* CSingleLinkedList::findMiddleNode()
{
	if (head == nullptr || head->next == nullptr)
		return nullptr;

	StNode *slow = head;
	StNode *fast = head;

	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}


void CSingleLinkedList::delLastKth(const int& k)
{
	if (head == nullptr || head->next == nullptr)
		return;
	StNode* fast = head;
	int i = 0;
	while ((fast != nullptr) && (i < k))
	{
		fast = fast->next;
		++i;
	}
	//the total number is smaller than k
	if (fast == nullptr) return;

	StNode* slow = head->next;
	StNode* prev = head;

	while (fast != nullptr && fast->next != nullptr)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next;
	}

	if (prev != nullptr && slow != nullptr)
	{
		prev->next = slow->next;
		slow->next = nullptr;
		delete slow;
	}
	return;
}


void CSingleLinkedList::printSingleLinkedList()
{
	if (head == nullptr)
		return;
	StNode* tmp = head->next;
	while (tmp != nullptr)
	{
		printf("%d\t", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}