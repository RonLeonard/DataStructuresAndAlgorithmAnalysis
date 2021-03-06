﻿
#include <iostream>
#include "linkedlist.h"




CLinkedList::CLinkedList() :head(nullptr), size(15), length(0)
{

}



CLinkedList::~CLinkedList()
{
	stNode* curPos;
	while (head != nullptr)
	{
		curPos = head;
		head = head->pNext;
		delete curPos;
		curPos = nullptr;
	}
	size = 0;
	length = 0;
}


/*************************************************************
*1. worst case time complexity: O(1)
*2. best case time complexity: O(n)
*3. average case time complexity: O(n)
************************************************************/
bool CLinkedList::insertNode(int val, int idx)
{
	if (idx >= size)
	{
		std::cout << "the postion beyond the size of linklist." << std::endl;
		return false;
	}

	if (idx > length)
	{
		std::cout << "the postion beyond the length of linklist." << std::endl;
		return false;
	}

	int i = 0;
	stNode* insertNode = nullptr;
	insertNode = new stNode;
	if (insertNode == nullptr)
	{
		std::cout << "new failed" << std::endl;
		return false;
	}

	insertNode->nodeData = val;

	if (idx == 0)
	{
		if (head != nullptr)
		{
			insertNode->pNext = head;
		}
		head = insertNode;
	}
	else
	{
		stNode* scout_soldier = head;
		for (int i = 0; i < idx - 1; i++)
		{
			scout_soldier = scout_soldier->pNext;
		}

		insertNode->pNext = scout_soldier->pNext;
		scout_soldier->pNext = insertNode;
	}

	length += 1;
	return true;
}



bool CLinkedList::delNode(int nodeVal)
{
	stNode* pscout_soldier = head;
	while (pscout_soldier != nullptr)
	{
		if (pscout_soldier->nodeData == nodeVal)
		{
			head = head->pNext;
			delete pscout_soldier;
			pscout_soldier = head;
			length -= 1;
		}
		else
		{
			if ((pscout_soldier->pNext != nullptr) && (pscout_soldier->pNext->nodeData == nodeVal))
			{
				stNode* tmp = pscout_soldier->pNext;
				pscout_soldier->pNext = pscout_soldier->pNext->pNext;
				delete tmp;
				length -= 1;
			}
			pscout_soldier = pscout_soldier->pNext;
		}
	}
	return true;
}



bool CLinkedList::delNode(unsigned int idx)
{
	if (idx >= size)
	{
		std::cout << "delete node failed, cause idx >= size." << std::endl;
		return false;
	}

	if (idx >= length)
	{
		std::cout << "delete node failed, cause idx >= length." << std::endl;
		return false;
	}

	if (idx == 0)
	{
		stNode* tmpNode = head;
		head = head->pNext;
		delete tmpNode;
		length -= 1;
		return true;
	}
	stNode* scout_soldier = head;
	idx -= 1;
	while (idx--)
	{
		scout_soldier = scout_soldier->pNext;
	}
	stNode* tmpNode = scout_soldier->pNext;
	scout_soldier->pNext = scout_soldier->pNext->pNext;
	delete tmpNode;
	length -= 1;
	return true;
}



bool CLinkedList::delTailNode()
{
	if (head == nullptr)
	{
		std::cout << "linked list is null." << std::endl;
		return false;
	}

	if (head->pNext == nullptr)
	{
		delete head;
		head = nullptr;
	}
	else
	{
		stNode* scout_solider = head;
		int tmpLen = length - 1;
		while (scout_solider->pNext->pNext != nullptr)
		{
			scout_solider = scout_solider->pNext;
		}

		delete scout_solider->pNext;
		scout_solider->pNext = nullptr;
	}
	return true;
}



/*************************************************************
*1. worst case time complexity: O(1)
*2. best case time complexity: O(n)
*3. average case time complexity: O(n)
************************************************************/
stNode* CLinkedList::findFirstPos(int val)
{
	if (head == nullptr)
	{
		std::cout << "the linked list is null." << std::endl;
		return nullptr;
	}
	stNode* scout_soldier = head;
	while (scout_soldier != nullptr)
	{
		if (scout_soldier->nodeData == val)
		{
			return scout_soldier;
		}
		else
		{
			scout_soldier = scout_soldier->pNext;
		}
	}
	return nullptr;
}



stNode* CLinkedList::findNode(unsigned int idx)
{
	if (idx >= length)
	{
		std::cout << "find node failed, cause idx >= length." << std::endl;
		return nullptr;
	}

	stNode* scout_soldier = head;
	while (idx--)
	{
		scout_soldier = scout_soldier->pNext;
	}
	return scout_soldier;
}


void CLinkedList::printLinkedListNode()
{
	if (head == nullptr)
	{
		std::cout << "linked list is null." << std::endl;
	}
	else
	{
		stNode* scout_soldier = head;
		while (scout_soldier != nullptr)
		{
			std::cout << scout_soldier->nodeData << "\t";
			scout_soldier = scout_soldier->pNext;
		}
		std::cout << std::endl;
	}
	return;
}


stNode* CLinkedList::getHeadNodePtr()
{
	return head;
}


int CLinkedList::valueIsExist(const int& val)
{
	if (head == nullptr)
	{
		std::cout << "the linked list is null." << std::endl;
		return -1;
	}

	stNode* scout_soldier = head;
	unsigned int tmpIdx = 0;
	while (scout_soldier != nullptr)
	{
		if (scout_soldier->nodeData == val)
		{
			return tmpIdx;
		}
		tmpIdx++;
		scout_soldier = scout_soldier->pNext;
	}
	return -1;
}



bool CLinkedList::linkedlistIsFull()
{
	return (length >= size ? true : false);
}


int CLinkedList::getLengthOfLinkedList()
{
	return length;
}


bool CLinkedList::inverseLInkedList()
{
	stNode * scout_solider, *prev, *save;

	if (head == nullptr)// zero node
	{
		std::cout << "the linked list is null." << std::endl;
		return false;
	}

	if (head->pNext == nullptr)
	{
		std::cout << "the linked list has only one node." << std::endl;
		return false;
	}

	scout_solider = head;
	prev = scout_solider->pNext;
	save = prev->pNext;
	
	while (save != nullptr)
	{
		prev->pNext = scout_solider;
		scout_solider = prev;
		prev = save;
		save = save->pNext;
	}
	prev->pNext = scout_solider;
	head->pNext = nullptr;
	head = prev;
	return true;
}


stNode* CLinkedList::getMidNodeOfLinkedList()
{
	stNode *slow, *fast;
	stNode *mid;
	if (head == nullptr)
	{
		std::cout << "the linked list is null." << std::endl;
		return nullptr;
	}
	if (head->pNext == nullptr)
	{
		std::cout << "the linked list has only one node." << std::endl;
		return head;
	}

	slow = head;
	fast = head;
	mid = head;
	bool isEven = false;
	while (fast->pNext != nullptr)
	{
		slow = slow->pNext;
		fast = fast->pNext;
		if (fast->pNext != nullptr)
		{
			fast = fast->pNext;
			mid = slow;
		}
		else
		{
			isEven = true;
		}
	}

	if (isEven == true)//even
		return mid;
	else
		return slow;

}