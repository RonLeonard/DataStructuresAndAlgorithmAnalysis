#include <iostream>
#include "guardlinkedlist.h"
CGuardLinkedList::CGuardLinkedList()
	: mSize(1)
{
	head = new stListNode();
	head->data = 0;
	head->pNext = nullptr;
}


CGuardLinkedList::~CGuardLinkedList()
{
	while (head != nullptr)
	{
		stListNode* tmpNode = head;
		head = head->pNext;
		delete tmpNode;
		tmpNode = nullptr;
	}
	mSize = 0;
}


stListNode* CGuardLinkedList::findFirstPos(int val)
{
	stListNode* scout_solider = head->pNext;
	while (scout_solider != nullptr)
	{
		if (scout_solider->data == val)
			return scout_solider;
		scout_solider = scout_solider->pNext;
	}
	std::cout << "there is no the specified value in the linked list." << std::endl;
	return nullptr;
}


stListNode* CGuardLinkedList::findVal(unsigned int idx)
{
	return nullptr;

}


bool CGuardLinkedList::delNode(int val)
{
	bool ret = false;
	if (head->pNext == nullptr)
	{
		std::cout << "the linked list is null." << std::endl;
		return false;
	}

	stListNode* scout_solider = head;
	while (scout_solider->pNext != nullptr)
	{
		if (scout_solider->pNext->data == val)
		{
			stListNode* tmpNode = scout_solider->pNext;
			scout_solider->pNext = scout_solider->pNext->pNext;
			delete tmpNode;
			tmpNode = nullptr;
			mSize -= 1;
			ret = true;
		}
		else
			scout_solider = scout_solider->pNext;
	}
	return ret;
}


bool CGuardLinkedList::delNode(unsigned int idx)
{
	if (mSize <= 1)
	{
		std::cout << "the linked list is null." << std::endl;
		return false;
	}

	if (idx >= mSize || idx == 0)
	{
		std::cout << "the index beyond of the size of the linked list." << std::endl;
		return false;
	}

	stListNode* scout_solider = head;
	unsigned int tmpIdx = 1;
	while (scout_solider->pNext != nullptr)
	{
		if (tmpIdx == idx)
		{
			stListNode* tmpNode = scout_solider->pNext;
			scout_solider->pNext = scout_solider->pNext->pNext;
			delete tmpNode;
			tmpNode = nullptr;
			return true;
		}
		tmpIdx++;
		scout_solider = scout_solider->pNext;
	}
}


bool CGuardLinkedList::insertNode(stListNode* pStListNode, unsigned int idx)
{
	if (idx > mSize)
	{
		std::cout << "the index beyond of the size of the linked list." << std::endl;
		return false;
	}
	if (idx == 0)
	{
		std::cout << "the index must bigger than zero." << std::endl;
		return false;
	}
	stListNode* scout_solider = head;
	while (idx--)
	{
		scout_solider = scout_solider->pNext;
	}

	pStListNode->pNext = scout_solider->pNext;
	scout_solider->pNext = pStListNode;
	return true;
}


void CGuardLinkedList::printLinkedList()
{
	if (head == nullptr)
	{
		std::cout << "the linked list is null." << std::endl;
	}
	stListNode* scout_solider = head->pNext;
	int index = 1;
	while (scout_solider != nullptr)
	{
		std::cout << "the no. " << index << " of the linked list's value is " << scout_solider->data << std::endl;
		scout_solider = scout_solider->pNext;
		index++;
	}
}