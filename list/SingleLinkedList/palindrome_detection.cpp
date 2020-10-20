#define PALINDROME_DETECTION_TEST
#ifdef PALINDROME_DETECTION_TEST
#include <iostream>
#include "SingleLinkedList_withguard.h"

using namespace std;


bool palindrome_detect(CSingleLinkedList_WithGuard* pSingleLinkedList)
{
	if (pSingleLinkedList == nullptr)
		return false;
	stNode* tmpNode = pSingleLinkedList->getHeadNode();
	if (tmpNode == nullptr || tmpNode->pNextNode == nullptr)
		return false;

	stNode* slowPtr = tmpNode;
	stNode* fastPtr = tmpNode;
	int cnt = 0;
	bool isOdd = false;
	
	while (fastPtr->pNextNode != nullptr)
	{
		slowPtr = slowPtr->pNextNode;
		fastPtr = fastPtr->pNextNode;
		if (fastPtr->pNextNode != nullptr)
		{
			fastPtr = fastPtr->pNextNode;
		}
		else
		{
			isOdd = true;
		}	  
	}

	stNode* prev = nullptr;
	stNode* cur = nullptr;
	stNode* next = nullptr;
	if (isOdd == true)
	{
		prev = slowPtr;
		cur = prev->pNextNode;
		prev->pNextNode = nullptr;
	}
	else
	{
		prev = slowPtr->pNextNode;
		slowPtr->pNextNode = nullptr;
		cur = prev->pNextNode;
		prev->pNextNode = nullptr;
	}
	while (cur != nullptr)
	{
		next = cur->pNextNode;
		cur->pNextNode = prev;
		prev = cur;
		cur = next;
	}

	stNode* front = tmpNode->pNextNode;
	stNode* end = prev;
	while (end != front)
	{
		if (end->data != front->data)
			return false;
		end = end->pNextNode;
		front = front->pNextNode;
	}
	return true;
}


int main(int argc, char* argv[])
{
	CSingleLinkedList_WithGuard* pLinkedList = new CSingleLinkedList_WithGuard();
	pLinkedList->insertStNode(0, 1);
	pLinkedList->insertStNode(1, 1);
	/*pLinkedList->insertStNode(2, 3);
	pLinkedList->insertStNode(3, 4);
	pLinkedList->insertStNode(0, 1);*/
	
	cout << "the linked list is:" << endl;
	pLinkedList->printStNode();

	bool isPalindrome = palindrome_detect(pLinkedList);
	if (isPalindrome)
	{
		cout << "the linked list is palindrome." << endl;
	}
	else
	{
		cout << "the linked list is not palindrome." << endl;
	}

	delete pLinkedList;
	pLinkedList = nullptr;
}


#endif