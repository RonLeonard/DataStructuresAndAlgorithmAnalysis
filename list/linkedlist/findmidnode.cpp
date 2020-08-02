#define FIND_MIDDLE_NODE_
#ifdef  FIND_MIDDLE_NODE_
#include <iostream>
#include "linkedlist.h"

int main(int argc, char *argv)
{
	CLinkedList* pLinkedList = new CLinkedList();
	if (pLinkedList == nullptr)
	{
		std::cout << "new CLinkedList" << std::endl;
		return false;
	}

	pLinkedList->insertNode(1, 0);
	pLinkedList->insertNode(2, 1);
	pLinkedList->insertNode(3, 2);
	pLinkedList->insertNode(4, 3);
	pLinkedList->insertNode(5, 4);

	std::cout << "the linked list is:" << std::endl;
	pLinkedList->printLinkedListNode();
	stNode *mid;
	mid = pLinkedList->getMidNodeOfLinkedList();
	if (mid != nullptr)
	{
		std::cout << "the mid node is: " << mid->nodeData << std::endl;
	}
	else
	{
		std::cout << "find mid node failed." << std::endl;
	}
	system("pause");
	return 0;
}

#endif