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
	stNode* ptr_prev;
	stNode* mid2 = nullptr;
	//find the middle of linked list
	while (ptr_fast->pNext != nullptr)
	{
		ptr_fast = ptr_fast->pNext;
		ptr_slow = ptr_slow->pNext;
		if (ptr_fast->pNext != nullptr)
		{
			ptr_fast = ptr_fast->pNext;
			mid2 = ptr_slow;//odd
			ptr_prev = ptr_slow;
		}
		else
		{
			mid2 = nullptr;//even
		}
	}

	stNode* mid = ptr_slow;
	stNode* elem, *prev, *save;

	if (mid2 != nullptr)//odd
	{
		elem = mid;
		prev = mid->pNext;
		save = prev->pNext;
		elem->pNext = nullptr;
		prev->pNext = elem;

		
	}
	else//even
	{
		ptr_prev->pNext = nullptr;
		elem = ptr_slow;
		prev = ptr_slow->pNext;
		save = prev->pNext;
		elem->pNext = nullptr;
		prev->pNext = elem;
		while (save != nullptr)
		{
			elem = prev;
			prev = save;
			save = save->pNext;
			prev->pNext = elem;
		}
		prev->pNext = elem;
	}

}

#endif