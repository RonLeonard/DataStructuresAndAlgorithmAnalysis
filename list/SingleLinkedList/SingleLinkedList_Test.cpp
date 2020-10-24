#define SINGLELINKEDLIST_FUNCTION_TEST
#ifdef SINGLELINKEDLIST_FUNCTION_TEST

#include <iostream>
using namespace std;

//#define NOGUARD_TEST
#define WITHGUARD_TEST
#ifdef WITHGUARD_TEST
#include "SingleLinkedList_withguard.h"
#endif
#ifdef NOGUARD_TEST
#include "SingleLinkedList_noguard.h"
#endif

int main(int argc, char *argv[])
{

#ifdef NOGUARD_TEST
	CSingleLinkedList_NoGuard *pCSingleLinkedList_NoGuard = new CSingleLinkedList_NoGuard();

	pCSingleLinkedList_NoGuard->insertStNode(0, 1);
	pCSingleLinkedList_NoGuard->insertStNode(1, 3);
	pCSingleLinkedList_NoGuard->insertStNode(2, 4);
	pCSingleLinkedList_NoGuard->insertStNode(3, 5);
	pCSingleLinkedList_NoGuard->insertStNode(1, 2);
	pCSingleLinkedList_NoGuard->insertStNode(0, 0);
	cout << "the linkedlist is 0 1 2 3 4 5 ?" << endl;
	pCSingleLinkedList_NoGuard->printStNode();
	pCSingleLinkedList_NoGuard->deleteStNode(0);
	pCSingleLinkedList_NoGuard->deleteStNode(2);
	pCSingleLinkedList_NoGuard->deleteStNode(3);
	cout << "the linkedlist is 1 2 4 ?" << endl;
	pCSingleLinkedList_NoGuard->printStNode();
	delete pCSingleLinkedList_NoGuard;
	pCSingleLinkedList_NoGuard = nullptr;
#endif


#ifdef WITHGUARD_TEST
	CSingleLinkedList_WithGuard* pCSingleLinkedList_WithGuard = new CSingleLinkedList_WithGuard();

	pCSingleLinkedList_WithGuard->insertStNode(0, 1);
	pCSingleLinkedList_WithGuard->insertStNode(1, 3);
	pCSingleLinkedList_WithGuard->insertStNode(2, 4);
	pCSingleLinkedList_WithGuard->insertStNode(3, 5);
	pCSingleLinkedList_WithGuard->insertStNode(1, 2);
	pCSingleLinkedList_WithGuard->insertStNode(0, 0);
	cout << "the linkedlist is 0 1 2 3 4 5 ?" << endl;
	pCSingleLinkedList_WithGuard->printStNode();
	pCSingleLinkedList_WithGuard->deleteStNode(0);
	pCSingleLinkedList_WithGuard->deleteStNode(2);
	pCSingleLinkedList_WithGuard->deleteStNode(3);
	cout << "the linkedlist is 1 2 4 ?" << endl;
	pCSingleLinkedList_WithGuard->printStNode();

/**********linkedlist reverse***********/
	pCSingleLinkedList_WithGuard->reverseLinkedList();
	cout << "the reversed linkedlist is 4 2 1 ?" << endl;
	pCSingleLinkedList_WithGuard->printStNode();
/**********linkedlist reverse***********/

	delete pCSingleLinkedList_WithGuard;
	pCSingleLinkedList_WithGuard = nullptr;
#endif
}

#endif