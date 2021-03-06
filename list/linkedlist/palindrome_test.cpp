//#define PALINDROME_TEST
#ifdef PALINDROME_TEST

#include <iostream>
#include "linkedlist.h"



bool checkLinkedListIsPalindrome(CLinkedList* pLinkedList)
{
	stNode* pHead = pLinkedList->getHeadNodePtr();
	if (pHead == nullptr)
	{
		std::cout << "the linked list is null." << std::endl;
		return false;
	}
	if (pHead->pNext == nullptr)
	{
		std::cout << "the linked list has only one node." << std::endl;
		return false;
	}

	if (pHead->pNext->pNext == nullptr)
	{
		if (pHead->nodeData == pHead->pNext->nodeData)
			return true;
		else
			return false;
	}
	//使用快慢指针
	stNode* ptr_slow = pHead;
	//向导作用
	stNode* ptr_fast = pHead;
	stNode* mid2 = pHead;
	bool isEven = false;

	
	//find the middle of linked list
	while (ptr_fast->pNext != nullptr)
	{
		ptr_fast = ptr_fast->pNext;
		ptr_slow = ptr_slow->pNext;
		if (ptr_fast->pNext != nullptr)
		{
			ptr_fast = ptr_fast->pNext;
			mid2 = ptr_slow;//odd
		}
		else
		{
			isEven = true;
		}
	}
	//reverse linked list
	stNode* mid = ptr_slow;
	stNode* elem, * prev, * save;


	elem = ptr_slow;
	prev = elem->pNext;
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

	if (isEven)
	{
		mid2->pNext = nullptr;
	}
	// compare the front half and end half of linked list
	stNode* front = pHead;
	stNode* end = prev;
	while (front != end)
	{
		if (front->nodeData != end->nodeData)
		{
			return false;
		}
		front = front->pNext;
		end = end->pNext;
	}
	return true;
}

bool isPalindrome(CLinkedList* pLinkedList, const int len)
{
	if (len == 0)
	{
		std::cout << "the linked list is null." << std::endl;
		return false;
	}

	int *pBuffer_1 = new int[len];
	int	*pBuffer_2 = new int[len];
	stNode* elem;
	for (int i = 0; i < len; i++)
	{
		elem = pLinkedList->findNode(i);
		pBuffer_1[i] = elem->nodeData;
		pBuffer_2[len - 1 - i] = elem->nodeData;
	}
	for (int i = 0; i < len; i++)
	{
		if (pBuffer_1[i] != pBuffer_2[i])
		{
			return false;
		}
	}

	delete[] pBuffer_1;
	delete[] pBuffer_2;
	return true;
}

int main(int argc, char** argv)
{
	bool ret = true;
	int len = 0;
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
	pLinkedList->insertNode(2, 3);
	pLinkedList->insertNode(1, 4);
	//pLinkedList->insertNode(1, 5);

	std::cout << "the linkedlist is:" << std::endl;
	pLinkedList->printLinkedListNode();

	len = pLinkedList->getLengthOfLinkedList();
	ret = isPalindrome(pLinkedList, len);
	if (ret)
	{
		std::cout << "the linked list is palindrome." << std::endl;
	}
	else
		std::cout << "the linked list is not palindrome." << std::endl;
	

	//method2
	std::cout << "------------------------------" << std::endl;
	std::cout << "------------------------------" << std::endl;
	CLinkedList* pLinkedList_2 = new CLinkedList();
	/*create a even palindrome 123321*/
	if (pLinkedList_2 == nullptr)
	{
		std::cout << "new CLinkedList failed." << std::endl;
		return false;
	}

	pLinkedList_2->insertNode(1, 0);
	pLinkedList_2->insertNode(2, 1);
	pLinkedList_2->insertNode(3, 2);
	pLinkedList_2->insertNode(1, 3);
	//pLinkedList_2->insertNode(1, 4);

	std::cout << "the linkedlist is:" << std::endl;
	pLinkedList_2->printLinkedListNode();
	ret = checkLinkedListIsPalindrome(pLinkedList_2);
	if (ret == false)
		std::cout << "the linked list is not palindrome." << std::endl;
	else
		std::cout << "the linked list is palindrome." << std::endl;
	
	delete pLinkedList;
	delete pLinkedList_2;
	system("pause");
	return 0;
}

#endif