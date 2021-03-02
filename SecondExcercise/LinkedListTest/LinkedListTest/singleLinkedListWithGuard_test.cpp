#define SINGLELINKEDLISTWITHGUARD_TEST_H
#ifdef SINGLELINKEDLISTWITHGUARD_TEST_H

#include "SingleLinkedListWithGuard.h"

//inverse linked list
stNode* inverseLinkedList(stNode* p)
{
    if (p == nullptr)
        return p;
    stNode *swap1 = p;
    stNode *swap2 = p->pNext;
    stNode *save;
    while (swap2 != nullptr)
    {
        save = swap2->pNext;
        swap2->pNext = swap1;

        swap1 = swap2;
        swap2 = save;
    }
	p->pNext = nullptr;
    return swap1;
}


bool isPalindromes(CSingleLinkedListWithGuard* p)
{
	bool ret = true;
    if (p == nullptr)
        return false;
    stNode* pFirstNode = p->getFirstNode();
    //p is null
    if (pFirstNode == nullptr)
        return false;
    //only one node
    if (pFirstNode->pNext == nullptr)
        return true;
	bool isEven = false;
    stNode *slow = pFirstNode;
    stNode *fast = pFirstNode->pNext;
	stNode *order= pFirstNode;
	stNode *inverse, *save_inverse;
    while (fast->pNext != nullptr && fast->pNext->pNext != nullptr)
    {
        slow = slow->pNext;
        fast = fast->pNext->pNext;
    }
	if (fast->pNext == nullptr)
	{
		isEven = true;
	}
    //inverse
    stNode* tmp = slow->pNext;
    inverse = inverseLinkedList(tmp);
    save_inverse = inverse;
    if (isEven == true)//even
    {
		slow->pNext = nullptr;//set guard node
    }

	//compare
	while (order != inverse)
	{
		if (order->data != inverse->data)
		{
			ret = false;
			break;
		}
		else
		{
			order = order->pNext;
			inverse = inverse->pNext;
		}
	}
	
	//resume str
	stNode *tmp2 = inverseLinkedList(save_inverse);
	if (isEven == true)//even
	{
		slow->pNext = tmp2;
	}
	return ret;
}

void test_member_function()
{
    CSingleLinkedListWithGuard* pSingleLinkedList = new CSingleLinkedListWithGuard();
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


void test_string_isPalindromes()
{
    CSingleLinkedListWithGuard* pSingleLinkedList = new CSingleLinkedListWithGuard();
    int val = 1;
    bool ret = false;
    printf("test case 1:\n\n");
    pSingleLinkedList->insertHead(val);
    printf("expected linked list is 1:\n\n");
    pSingleLinkedList->printLinkedList();
    ret = isPalindromes(pSingleLinkedList);
    printf("\nlinked list is palindromes: %d\n\n", ret);
    val = 2;
    pSingleLinkedList->insertHead(val);
    printf("expected linked list is 1, 1:\n\n");
    pSingleLinkedList->printLinkedList();
    ret = isPalindromes(pSingleLinkedList);
    printf("\nlinked list is palindromes: %d\n\n", ret);

    val = 3;
    pSingleLinkedList->insertHead(val);
    val = 2;
    pSingleLinkedList->insertHead(val);
    val = 1;
    pSingleLinkedList->insertHead(val);
    printf("expected linked list is 1, 1, 2, 1, 1:\n\n");
    pSingleLinkedList->printLinkedList();
    ret = isPalindromes(pSingleLinkedList);
    printf("\nlinked list is palindromes: %d\n\n", ret);
}

int main(int argc, char* argv)
{
    test_string_isPalindromes();
}


#endif