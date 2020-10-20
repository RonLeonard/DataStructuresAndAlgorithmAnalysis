//#define LRU_LINKEDLIST_TEST
#ifdef LRU_LINKEDLIST_TEST
#include <iostream>
#include "SingleLinkedList_withguard.h"

using namespace std;

void LRUBasedOnLinkedList_withguard(CSingleLinkedList_WithGuard *pCSingleLinkedList_WithGuard, int val)
{
	stNode* tmpNode = pCSingleLinkedList_WithGuard->findStNodeByVal(val);
	if (tmpNode != nullptr)
	{
		pCSingleLinkedList_WithGuard->deleteStNode(tmpNode);
	}
	
	pCSingleLinkedList_WithGuard->insertStNode(0, val);
}


int main(int argc, char* argv[])
{
	CSingleLinkedList_WithGuard* pCSingleLinkedList_WithGuard = new CSingleLinkedList_WithGuard();

	pCSingleLinkedList_WithGuard->insertStNode(0, 1);
	pCSingleLinkedList_WithGuard->insertStNode(1, 3);
	pCSingleLinkedList_WithGuard->insertStNode(2, 4);
	pCSingleLinkedList_WithGuard->insertStNode(3, 5);
	pCSingleLinkedList_WithGuard->insertStNode(1, 2);
	pCSingleLinkedList_WithGuard->insertStNode(0, 0);
	cout << "the linkedlist is 0 1 2 3 4 5 ?" << endl;
	pCSingleLinkedList_WithGuard->printStNode();
	
	LRUBasedOnLinkedList_withguard(pCSingleLinkedList_WithGuard, 3);
	cout << "the linkedlist is 3 0 1 2 4 5 ?" << endl;
	pCSingleLinkedList_WithGuard->printStNode();
	LRUBasedOnLinkedList_withguard(pCSingleLinkedList_WithGuard, 6);
	cout << "the linkedlist is 6 3 0 1 2 4 5 ?" << endl;
	pCSingleLinkedList_WithGuard->printStNode();
	delete pCSingleLinkedList_WithGuard;
	pCSingleLinkedList_WithGuard = nullptr;
}
#endif