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
		|| (pLinkedList_2 == nullptr)
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

	
	stNode* ptr1, * ptr2;
	int idx = 0;
	int value = 0;
	ptr1 = pLinkedList_1->getHeadNodePtr();
	ptr2 = pLinkedList_2->getHeadNodePtr();
	if (ptr1 == nullptr || ptr2 == nullptr)
	{
		std::cout << "At lease one linked list is null" << std::endl;
		return false;
	}

	while ((ptr1 != nullptr) && (ptr2 != nullptr))
	{
		if (ptr1->nodeData > ptr2->nodeData)
		{
			value = ptr2->nodeData;
			ptr2 = ptr2->pNext;
		}
		else
		{
			value = ptr1->nodeData;
			ptr1 = ptr1->pNext;
		}
		
		pLinkedList_merge->insertNode(value, idx);
		idx++;
	}

	stNode* ptr;
	ptr = (ptr1 != nullptr) ? ptr1 : ptr2;
	while (ptr != nullptr)
	{
		value = ptr->nodeData;
		pLinkedList_merge->insertNode(value, idx);
		idx++;
		ptr = ptr->pNext;
	}

	std::cout << "after merge the new linked list is:" << std::endl;
	pLinkedList_merge->printLinkedListNode();
	
	delete pLinkedList_1;
	delete pLinkedList_2;
	delete pLinkedList_merge;
	return 0;
}

#endif