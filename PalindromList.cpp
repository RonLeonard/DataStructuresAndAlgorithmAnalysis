#include <list>
#include <iostream>
#include "PalindromList.h"

using std::list;
using std::cout;
using std::endl;

PalindromList::PalindromList() :length(0)
{
     head = new SNode();
     head->next = nullptr;
     tail = head;
}


PalindromList::~PalindromList()
{
    SNode *ptr, *tmp;
    ptr = head;
    while (ptr->next != nullptr) {
        tmp = ptr->next;
        ptr->next = ptr->next->next;
        delete tmp;
    }
    delete head;
    head = nullptr;
    length = 0;
}
    
    
bool PalindromList::isEmpty()
{
    return length <= 0 ? true : false;
}


void PalindromList::insertElemAtHead(char elem)
{
    SNode *ptr = new SNode();
    ptr->data = elem;
    ptr->next = head->next;
    head->next = ptr;
    length++;
}


void PalindromList::insertElemAtTail(char elem)
{
    SNode *ptr = new SNode();
    ptr->data = elem;
    ptr->next = nullptr;
// the following two line is important, maybe cause segmentation fault
    tail->next = ptr;
    tail = ptr;
    length++;
}


void PalindromList::deleteTailNode()
{
    SNode *ptr, *tmp;
    ptr = head;
    while (ptr->next != nullptr) {
        tmp = ptr;
        ptr = ptr->next;
    }
    delete ptr;
    tmp = nullptr;
    length--;
    
}


void PalindromList::printList(const PalindromList &pList)
{
    SNode *ptr;
    ptr = head->next;
    while (ptr != nullptr) {
        cout << ptr->data;
        ptr = ptr->next;
    }
}


int PalindromList::getLength()
{
    return length;    
}


SNode * PalindromList::getNodeAtHeadNext()
{
    return head->next;
}