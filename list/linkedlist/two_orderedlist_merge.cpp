#define _MERGE_LIST
#ifdef  _MERGE_LIST

/**merge two ordered linked list**/


#include <iostream>
#include "linkedlist.h"
int main(int argc, char** argv)
{
	CLinkedList *pLinkedList_1 = new CLinkedList();
	CLinkedList* pLinkedList_2 = new CLinkedList();
	CLinkedList* pLinkedList_merge = new CLinkedList();

	if ((pLinkedList_1 == nullptr)
		|| (pLinkedList_1 == nullptr)
		|| (pLinkedList_merge == nullptr))
	{
		std::cout << "new  object of CLinkedList class failed." << std::endl;
		return 0;
	}

	pLinkedList_1->insertNode(1, 0);
	pLinkedList_1->insertNode(3, 1);
	pLinkedList_1->insertNode(4, 2);
	pLinkedList_1->insertNode(6, 3);
	pLinkedList_1->insertNode(7, 4);
	pLinkedList_1->insertNode(9, 5);
	std::cout << "the linked list is :" << std::endl;
	pLinkedList_1->printLinkedListNode();

	pLinkedList_2->insertNode(1, 0);
	pLinkedList_2->insertNode(4, 1);
	pLinkedList_2->insertNode(5, 2);
	pLinkedList_2->insertNode(7, 3);
	pLinkedList_2->insertNode(8, 4);
	pLinkedList_2->insertNode(10, 5);
	std::cout << "the linked list is :" << std::endl;
	pLinkedList_1->printLinkedListNode();


	stNode *scout_solider1, * scout_solider2, *merge

	return 0;
}

#endif