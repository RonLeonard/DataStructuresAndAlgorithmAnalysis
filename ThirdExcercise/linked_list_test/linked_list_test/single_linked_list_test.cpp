#include "single_linkedlist.h"


void test_fundamentalOperator(CSingleLinkedList* const p1)
{
	if (p1 == nullptr)
		return;
	p1->insertHead(2);
	p1->insertTail(3);
	p1->insertTail(6);
	p1->insertHead(1);

	StNode* pStNode = p1->findVal(2);
	p1->insertBefore(pStNode, 4);
	p1->insertAfter(pStNode, 5);
	p1->delNode(pStNode);
	p1->delVal(4);
	p1->printSingleLinkedList();
}


void test_inverseLinkedList(CSingleLinkedList* const p1)
{
	if (p1 == nullptr)
		return;
	p1->inverseLinkedList();
	p1->printSingleLinkedList();
}


void test_delLastKth(CSingleLinkedList* const p1)
{
	if (p1 == nullptr)
		return;
	p1->delLastKth(4);
	p1->printSingleLinkedList();
}


void mergeTwoSortedList(CSingleLinkedList* const p1, CSingleLinkedList* const p2, CSingleLinkedList* const p)
{
	if (p1 == nullptr || p2 == nullptr || p == nullptr)
		return;
	StNode* tmp1 = p1->getHead();
	StNode* tmp2 = p2->getHead();
	StNode* tmp = p->getHead();
	if (tmp1 == nullptr || tmp2 == nullptr || tmp == nullptr)
	{
		return;
	}
	else
	{
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}

	while (tmp1 != nullptr && tmp2 != nullptr)
	{
		if (tmp1->data < tmp2->data)
		{
			tmp->next = tmp1;
			tmp1 = tmp1->next;
			tmp = tmp->next;
		}
		else
		{
			tmp->next = tmp2;
			tmp2 = tmp2->next;
			tmp = tmp->next;
		}
	}
	while (tmp1 != nullptr)
	{
		tmp->next = tmp1;
		tmp1 = tmp1->next;
		tmp = tmp->next;
	}
	while (tmp2 != nullptr)
	{
		tmp->next = tmp2;
		tmp2 = tmp2->next;
		tmp = tmp->next;
	}
	return;
}


void test_mergeTwoSortedList()
{
	CSingleLinkedList* p1 = new CSingleLinkedList();
	//p1->insertTail(1);
	//p1->insertTail(3);
	CSingleLinkedList* p2 = new CSingleLinkedList();
	p2->insertTail(2);
	p2->insertTail(4);
	CSingleLinkedList* p = new CSingleLinkedList();
	mergeTwoSortedList(p1, p2, p);
	p->printSingleLinkedList();
}


bool isPalindromic(CSingleLinkedList* p)
{
	if (p == nullptr || p->getHead() == nullptr || p->getHead()->next == nullptr)
		return false;
	
	StNode* slow = p->getHead();
	StNode* fast = p->getHead();
	StNode* prev = nullptr;
	
	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast == nullptr)//odd
	{
		prev = slow;
		StNode* cur = slow->next;
		StNode* next = nullptr;
		slow->next = nullptr;
		while (cur != nullptr)
		{
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
	}
	else if (fast->next == nullptr)//even
	{
		prev = slow->next;
		StNode* cur = prev->next;
		StNode* next = nullptr;
		slow->next = nullptr;
		prev->next = nullptr;
		
		while (cur != nullptr)
		{
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
	}

	//compare
	StNode* tmp1 = p->getHead()->next;
	StNode* tmp2 = prev;

	while (tmp1 != tmp2)
	{
		if (tmp1 != nullptr && tmp2 != nullptr
			&& tmp1->data != tmp2->data)
			break;
	}

	if (tmp1 == tmp2)
		return true;
	else
		return false;
}


int main(int argc, char* argv[])
{
	CSingleLinkedList *p1 = new CSingleLinkedList();

	test_fundamentalOperator(p1);
	
	test_inverseLinkedList(p1);

	test_delLastKth(p1);

	test_mergeTwoSortedList();
	return 0;
}