#define LRU_IMPLEMENT_
#ifdef LRU_IMPLEMENT_


#include <iostream>
#include "linkedlist.h"

int main(int argc, char** argv)
{
	CLinkedList* pLinkedList = new CLinkedList();
	int ret = 0;

	int value = 1;
	pLinkedList->insertNode(value, 0);
	value = 2;
	pLinkedList->insertNode(value, 1);
	value = 3;
	pLinkedList->insertNode(value, 2);
	value = 4;
	pLinkedList->insertNode(value, 3);
	value = 5;
	pLinkedList->insertNode(value, 4);
	value = 6;
	pLinkedList->insertNode(value, 5);
	value = 7;
	pLinkedList->insertNode(value, 6);
	value = 8;
	pLinkedList->insertNode(value, 7);
	value = 9;
	pLinkedList->insertNode(value, 8);
	std::cout << "the linked list is 1, 2, 3, 4, 5, 6, 7, 8, 9 ?" << std::endl;
	pLinkedList->printLinkedListNode();


	/***********case 1: 当访问一个链表中已存在的元素*****************/
	int val1 = 2;
	ret = pLinkedList->valueIsExist(val1);
	if (ret < 0)// the value is no exist
	{
		bool flag = false;
		flag = pLinkedList->linkedlistIsFull();
		if (!flag)//linked list has space
		{
			pLinkedList->insertNode(val1, 0);
		}
		else
		{
			pLinkedList->delTailNode();//delete the tail node.
			pLinkedList->insertNode(val1, 0);
		}
	}
	else//the value is exist
	{
		
		pLinkedList->delNode((unsigned int)ret);
		pLinkedList->insertNode(val1, 0);
	}
	std::cout << "the linked list is 2, 1, 3, 4, 5, 6, 7, 8, 9 ?" << std::endl;
	pLinkedList->printLinkedListNode();
	/***********case 1: 当访问一个链表中已存在的元素*****************/

	/***********case 2: 当访问一个链表中不存在的元素, 且链表未满*****************/
	int val2 = 10;
	ret = pLinkedList->valueIsExist(val2);
	if (ret < 0)// the value is no exist
	{
		bool flag = pLinkedList->linkedlistIsFull();
		if (!flag)//linked list has space
		{
			pLinkedList->insertNode(val2, 0);
		}
		else// delete tail node , then insert.
		{
			pLinkedList->delTailNode();//delete the tail node.
			pLinkedList->insertNode(val2, 0);
		}
	}
	else
	{
		pLinkedList->delNode((unsigned int)ret);
		pLinkedList->insertNode(val2, 0);
	}
	std::cout << "the linked list is 10, 2, 1, 3, 4, 5, 6, 7, 8, 9 ?" << std::endl;
	pLinkedList->printLinkedListNode();

	/***********case 2: 当访问一个链表中不存在的元素, 且链表未满*****************/

	/***********case 3: 当访问一个链表中不存在的元素, 且链表已满*****************/
	int val3 = 11;
	ret = pLinkedList->valueIsExist(val3);
	if (ret < 0)// the value is no exist
	{
		bool flag = pLinkedList->linkedlistIsFull();
		if (!flag)//linked list has space
		{
			pLinkedList->insertNode(val3, 0);
		}
		else// delete tail node , then insert.
		{
			pLinkedList->delTailNode();//delete the tail node.
			pLinkedList->insertNode(val3, 0);
		}
	}
	else
	{
		pLinkedList->delNode((unsigned int)ret);
		pLinkedList->insertNode(val3, 0);
	}
	std::cout << "the linked list is 11, 10, 2, 1, 3, 4, 5, 6, 7, 8 ?" << std::endl;
	pLinkedList->printLinkedListNode();
	system("pause");
	return 0;
}

#endif