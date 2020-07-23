#define PALINDROME_TEST
#ifdef PALINDROME_TEST

#include <iostream>
#include "linkedlist.h"

int main(int argc, char** argv)
{

	CLinkedList* pLinkedList = new CLinkedList();
	/*create a even palindrome 123321*/
	if (pLinkedList == nullptr)
	{
		std::cout << "new CLinkedList failed." << std::endl;
		return false;
	}

	pLinkedList->insertNode(1, 0);
	pLinkedList->insertNode(2, 1);
	pLinkedList->insertNode(3, 2);
	pLinkedList->insertNode(3, 3);
	pLinkedList->insertNode(2, 4);
	pLinkedList->insertNode(1, 5);

	std::cout << "the linkedlist is 1, 2, 3, 3, 2, 1?" << std::endl;
	pLinkedList->printLinkedListNode();

	//使用快慢指针
	stNode* ptr_slow = pLinkedList->getHeadNodePtr();
	//向导作用
	stNode* ptr_fast = pLinkedList->getHeadNodePtr();
	while (ptr_fast != nullptr)
	{

		ptr_fast = ptr_fast->pNext->pNext;
	}
}

#endif