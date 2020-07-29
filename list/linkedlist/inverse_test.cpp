//#define INVERSE_TEST
#ifdef INVERSE_TEST
#include <iostream>
#include "linkedlist.h"

int main(int argc, char** argv)
{
	CLinkedList* pCLinkedList = new CLinkedList();
	/*case 1: test no node*/
	pCLinkedList->inverseLInkedList();
	/*case 1: test no node*/

	/*case 2: test only one node*/
	pCLinkedList->insertNode(1, 0);
	pCLinkedList->inverseLInkedList();
	/*case 2: test only one node*/


	/*case 3: test two node*/
	pCLinkedList->insertNode(2, 1);
	std::cout << "the linked list is 1, 2 ?" << std::endl;
	pCLinkedList->printLinkedListNode();

	std::cout << "inverse it, and the new linked list is 2, 1 ?" << std::endl;
	pCLinkedList->inverseLInkedList();
	pCLinkedList->printLinkedListNode();

	std::cout << "inverse it once more, and the new linked list is 1, 2 ?" << std::endl;

	pCLinkedList->inverseLInkedList();
	pCLinkedList->printLinkedListNode();

	/*case 3: test two node*/

	/*case 3: test five node*/
	pCLinkedList->insertNode(3, 2);
	pCLinkedList->insertNode(4, 3);
	pCLinkedList->insertNode(5, 4);
	std::cout << "the linked list is 1, 2, 3, 4, 5 ?" << std::endl;
	pCLinkedList->printLinkedListNode();

	std::cout << "inverse it, and the new linked list is 5, 4, 3, 2, 1 ?" << std::endl;
	pCLinkedList->inverseLInkedList();
	pCLinkedList->printLinkedListNode();

	/*case 3: test five node*/

	system("pause");
	return 0;
}
#endif