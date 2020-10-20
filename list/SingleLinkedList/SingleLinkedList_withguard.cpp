#include <iostream>
#include "SingleLinkedList_withguard.h"

using namespace std;

CSingleLinkedList_WithGuard::CSingleLinkedList_WithGuard()
{
	size = 0;
	stNode* guardNode = new stNode();
	
	head = guardNode;
}


CSingleLinkedList_WithGuard::~CSingleLinkedList_WithGuard()
{
	size = 0;
	while (head != nullptr)
	{
		stNode* tmpNode = head;
		head = head->pNextNode;
		delete tmpNode;
		tmpNode = nullptr;
	}
}


bool CSingleLinkedList_WithGuard::insertStNode(int idx, int data)
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

	stNode* insertNode = new stNode();
	if (insertNode == nullptr)
	{
		cout << "Function: insertNode Failed. Cause new stNode faild." << endl;
		return false;
	}
	insertNode->data = data;


	stNode* tmpNode = head;
	for (int i = 0; i < idx; i++)
	{
		tmpNode = tmpNode->pNextNode;
	}
	insertNode->pNextNode = tmpNode->pNextNode;
	tmpNode->pNextNode = insertNode;
	size += 1;
	return true;
}


bool CSingleLinkedList_WithGuard::deleteStNode(int idx)
{
	if (idx < 0)
	{
		cout << "the idx must be a positive number." << endl;
		return false;
	}
	if (idx >= size)
	{
		cout << "the idx exceed the size of LinkedList" << endl;
		return false;
	}

	stNode* tmpNode = head;
	for (int i = 0; i < idx; i++)
	{
		tmpNode = tmpNode->pNextNode;
	}
	stNode* tmpNode_del = tmpNode->pNextNode;
	tmpNode->pNextNode = tmpNode->pNextNode->pNextNode;
	delete tmpNode_del;
	tmpNode_del = nullptr;
	size -= 1;
	return true;
}


bool CSingleLinkedList_WithGuard::deleteStNode(stNode* specifiedIdx)
{
	if (specifiedIdx == nullptr || head == nullptr)
		return false;
	stNode* tmpNode = head;
	while (tmpNode != nullptr && tmpNode->pNextNode != specifiedIdx)
	{
		tmpNode = tmpNode->pNextNode;
	}
	if (tmpNode == nullptr)
		return false;
	else
	{ 
		tmpNode->pNextNode = tmpNode->pNextNode->pNextNode;
		delete specifiedIdx;
		specifiedIdx = nullptr;
		size -= 1;
		return true;
	}
}


stNode* CSingleLinkedList_WithGuard::findStNodeByIdx(int idx)
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
	return tmpNode->pNextNode;
}


stNode* CSingleLinkedList_WithGuard::findStNodeByVal(int val)
{
	stNode* tmpNode = head->pNextNode;
	while (tmpNode != nullptr && tmpNode->data != val)
	{
		tmpNode = tmpNode->pNextNode;
	}
	
	return tmpNode;
}


void CSingleLinkedList_WithGuard::printStNode()
{
	stNode* tmpNode = head->pNextNode;
	while (tmpNode != nullptr)
	{
		cout << tmpNode->data << " ";
		tmpNode = tmpNode->pNextNode;
	}
	cout << endl;
}


stNode* CSingleLinkedList_WithGuard::getHeadNode()
{
	return head;
}