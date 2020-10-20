#include <iostream>
#include "SingleLinkedList_noguard.h"

using namespace std;

CSingleLinkedList_NoGuard::CSingleLinkedList_NoGuard()
{
	size = 0;
	head = nullptr;
}

	

CSingleLinkedList_NoGuard::~CSingleLinkedList_NoGuard()
{
	size = 0;
	if (head != nullptr)
	{
		stNode* tmpNode = head;
		head = head->pNextNode;
		delete tmpNode;
		tmpNode = nullptr;
	}
}


bool CSingleLinkedList_NoGuard::insertStNode(int idx, int data)
{
	if (idx < 0)
	{
		cout << "the idx must be a positive number." << endl;
		return false;
	}
	if (idx > size)
	{
		cout << "the idx exceed the size of LinkedList" << endl;
		return false;
	}
	
	//create a new stNode
	stNode* pStNode = new stNode();
	if (pStNode == nullptr)
	{
		cout << "Function: insertNode Failed. Cause new stNode faild." << endl;
		return false;
	}
	pStNode->data = data;

	//insert the new stNode
	if (idx == 0)
	{
		pStNode->pNextNode = head;
		head = pStNode;
	}
	else
	{
		stNode* tmpNode = head;
		for (int i = 0; i < idx - 1; i++)
		{
			tmpNode = tmpNode->pNextNode;
		}

		pStNode->pNextNode = tmpNode->pNextNode;
		tmpNode->pNextNode = pStNode;	
	}
	size += 1;
	return true;
}
	

bool CSingleLinkedList_NoGuard::deleteStNode(int idx)
{
	if (idx < 0)
	{
		cout << "the idx must be bigger than or equal to zero." << endl;
		return false;
	}
	if (idx >= size)
	{
		cout << "the idx exceed the size of LinkedList" << endl;
		return false;
	}

	if (idx == 0)
	{
		stNode* tmpNode_del = head;
		head = head->pNextNode;
		delete tmpNode_del;
		tmpNode_del = nullptr;
	}
	else
	{
		stNode* tmpNode = head;
		for (int i = 0; i < idx - 1; i++)
		{
			tmpNode = tmpNode->pNextNode;
		}
		stNode* tmpNode_del = tmpNode->pNextNode;
		tmpNode->pNextNode = tmpNode->pNextNode->pNextNode;
		delete tmpNode_del;
		tmpNode_del = nullptr;
	}
	size -= 1;
	return true;
}
	


stNode* CSingleLinkedList_NoGuard::findStNode(int idx)
{
	if (idx < 0)
	{
		cout << "the idx must be bigger than or equal to zero." << endl;
		return nullptr;
	}
	if (idx >= size)
	{
		cout << "the idx exceed the size of LinkedList" << endl;
		return nullptr;
	}
	
	stNode* tmpNode = head;

	for (int i = 0; i < idx; i++)
	{
		tmpNode = tmpNode->pNextNode;
	}
	return tmpNode;
}

void CSingleLinkedList_NoGuard::printStNode()
{
	stNode* tmpNode = head;
	while (tmpNode)
	{
		cout << tmpNode->data << " ";
		tmpNode = tmpNode->pNextNode;
	}
	cout << endl;
	return;
}
