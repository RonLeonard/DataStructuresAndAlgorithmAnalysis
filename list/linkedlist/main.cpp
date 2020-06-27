#include <iostream>
#include "linkedlist.h"



int main(int argc, char ** argv)
{
	CLinkedList *linkedlist;
	linkedlist = new CLinkedList();

// test insert node
	bool ret = false;
	ret = linkedlist->insertNode(3, 3);
	if (ret == false)
	{
		std::cout << "insert node failed" << std::endl;
	}

}