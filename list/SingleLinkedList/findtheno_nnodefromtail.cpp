#define FIND_THE_NO_N_NODEFROM_TRAIL
#ifdef FIND_THE_NO_N_NODEFROM_TRAIL

#include "SingleLinkedList_withguard.h"
#include <iostream>

using namespace std;

bool findTheNo_nNodeFromTail(CSingleLinkedList_WithGuard* pLinkedList, int n, int &val)
{
	if (n <= 0)
	{
		cout << "the input number must bigger than zero." << endl;
		return false;
	}

	stNode *pHead = pLinkedList->getHeadNode();
	if (pHead == nullptr || pHead->pNextNode == nullptr)
	{
		cout << "the linked list is null." << endl;
		return false;
	}
	stNode* p = pHead->pNextNode;
	stNode* q = pHead->pNextNode;

	for (int i = 1; i < n; i++)
	{
		if (q->pNextNode == nullptr)
		{
			cout << "the no. n beyond the size of linked list." << endl;
			return false;
		}
		else
		{
			q = q->pNextNode;
		}
	}

	while (q->pNextNode != nullptr)
	{
		p = p->pNextNode;
		q = q->pNextNode;
	}

	val = p->data;
	return true;
}


int main(int argc, char** argv)
{
	CSingleLinkedList_WithGuard* pLinkedList = new CSingleLinkedList_WithGuard();
	pLinkedList->insertStNode(0, 1);
	pLinkedList->insertStNode(1, 2);
	pLinkedList->insertStNode(2, 3);
	pLinkedList->insertStNode(3, 4);
	pLinkedList->insertStNode(4, 5);
	int val = 0;
	bool res = false;
	res = findTheNo_nNodeFromTail(pLinkedList, 6, val);
	if (res)
	{
		cout << "val = " << val << endl;
	}
	else
		cout << "find failed." << endl;
	return 0;
}
#endif