#include <iostream>
#include "linkedlist.h"



int main(int argc, char ** argv)
{
	CLinkedList *linkedlist;
	linkedlist = new CLinkedList();

// test insert node
	bool ret = false;
	//case 1: idx > size
	ret = linkedlist->insertNode(3, 3);
	if (ret == false)
	{
		std::cout << "insert node failed" << std::endl;
	}
	// case 2: head == nullptr, idx == 0
	ret = linkedlist->insertNode(3, 0);
	if (ret == true)
	{
		std::cout << "insert node succeed" << std::endl;
	}

	// case 3: head != nullptr idx == 0
	ret = linkedlist->insertNode(1, 0);
	if (ret == true)
	{
		std::cout << "insert node succeed" << std::endl;
	}

	// case 3: idx < size
	ret = linkedlist->insertNode(2, 1);
	if (ret == true)
	{
		std::cout << "insert node succeed" << std::endl;
	}

	// case 3: idx == size
	ret = linkedlist->insertNode(4, 3);
	if (ret == true)
	{
		std::cout << "insert node succeed" << std::endl;
	}
	ret = linkedlist->insertNode(5, 4);
	if (ret == true)
	{
		std::cout << "insert node succeed" << std::endl;
	}

	//test linked list is: 1, 2, 3, 4, 5?
	std::cout << "linked list is :" << std::endl;
	linkedlist->printLinkedListNode();

	//delete node of the specified value
	ret = linkedlist->delNode(2);
	std::cout << "the new linked list is :" << std::endl;
	linkedlist->printLinkedListNode();

	/*****delete node of the specified idx*******/
	//idx >= size
	unsigned int idx1 = 4;
	ret = linkedlist->delNode(idx1);
	std::cout << "the new linked list is :" << std::endl;
	linkedlist->printLinkedListNode();

	//idx == 0
	unsigned int idx2 = 0;
	ret = linkedlist->delNode(idx2);
	std::cout << "the new linked list is :" << std::endl;
	linkedlist->printLinkedListNode();

	//idx < size
	unsigned int idx3 = 1;
	ret = linkedlist->delNode(idx3);
	std::cout << "the new linked list is :" << std::endl;
	linkedlist->printLinkedListNode();
	/*****delete node of the specified idx*******/

	system("pause");
	return 0;
}