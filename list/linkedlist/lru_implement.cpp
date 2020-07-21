#define LRU_IMPLEMENT_
#ifdef LRU_IMPLEMENT_


#include <iostream>
#include "linkedlist.h"

int main(int argc, char** argv)
{
	CLinkedList* pLinkedList = new CLinkedList();
	int val1 = 2;
	int ret = 0;
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
			pLinkedList->delNode
		}
	}
}

#endif