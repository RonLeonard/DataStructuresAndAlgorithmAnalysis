// linkedlist.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "linkedlist.h"




CLinkedList::CLinkedList():head(nullptr), size(0)
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
}



bool CLinkedList::insertNode(int val, int idx)
{
	
	if (idx > size)
	{
		std::cout << "the postion beyond the size of linklist." << std::endl;
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
	stNode* scout_soldier = head;
	
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
		for (int i = 0; i < (idx == size) ? idx : idx - 1; i++)
		{
			scout_soldier = scout_soldier->pNext;
		}

		insertNode->pNext = scout_soldier->pNext;
		scout_soldier->pNext = insertNode;
	}

	size += 1;
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
			size -= 1;
		}
		else
		{	
			if ((pscout_soldier->pNext != nullptr) && (pscout_soldier->pNext->nodeData == nodeVal))
			{
				stNode* tmp = pscout_soldier->pNext;
				pscout_soldier->pNext = pscout_soldier->pNext->pNext;
				delete tmp;
				size -= 1;
			}
			pscout_soldier = pscout_soldier->pNext;
		}
	}
}



bool CLinkedList::delNode(stNode* pNode)
{


}


stNode* CLinkedList::findVal(int val)
{


}

