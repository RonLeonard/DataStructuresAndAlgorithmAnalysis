#define _SINGLELINKEDLIST_TEST_
#ifdef _SINGLELINKEDLIST_TEST_
#include <iostream>
#include "SingleLinkedList.h"


int main()
{
    CSingleLinkedList* pSingleLinkedList = new CSingleLinkedList();
    int val = 1;
    printf("test case 1:\n\n");
    pSingleLinkedList->insertHead(val);
    stNode* pNode = new stNode(0, nullptr);
    pSingleLinkedList->insertHead(pNode);
    val = 2;
    pSingleLinkedList->insertTail(val);

    stNode* pNode2 = new stNode(3, nullptr);
    pSingleLinkedList->insertTail(pNode2);
    printf("expected linked list is 0 1 2 3:\n\n");
    pSingleLinkedList->printLinkedList();

    printf("\n\ntest case 2:\n\n");
    stNode* tmp = pSingleLinkedList->findByVal(1);
    pSingleLinkedList->insertBefore(tmp, 4);

    tmp = pSingleLinkedList->findByIndex(2);
    pSingleLinkedList->insertAfter(tmp, 5);
    printf("expected linked list is 0 4 1 5 2 3:\n\n");
    pSingleLinkedList->printLinkedList();

    printf("\n\ntest case 3:\n\n");
    pSingleLinkedList->deleteNode(0);
    tmp = pSingleLinkedList->findByIndex(2);
    pSingleLinkedList->deleteNode(tmp);
    printf("expected linked list is 4 1 2 3:\n\n");
    pSingleLinkedList->printLinkedList();
}

#endif
