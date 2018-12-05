#include <list>
#include <iostream>
#include "SinglyLinkedList.h"

using std::list;
using std::cout;
using std::endl;

SinglyLinkedList::SinglyLinkedList() :length(0)
{
     head = new SNode();
     head->next = nullptr;
     tail = head;
}


SinglyLinkedList::~SinglyLinkedList()
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
    
    
bool SinglyLinkedList::isEmpty()
{
    return length <= 0 ? true : false;
}


void SinglyLinkedList::insertElemAtHead(char elem)
{
    SNode *ptr = new SNode();
    ptr->data = elem;
    ptr->next = head->next;
    head->next = ptr;
    length++;
}


void SinglyLinkedList::insertElemAtTail(char elem)
{
    SNode *ptr = new SNode();
    ptr->data = elem;
    ptr->next = nullptr;
// the following two line is important, maybe cause segmentation fault
    tail->next = ptr;
    tail = ptr;
    length++;
}


void SinglyLinkedList::deleteTailNode()
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


void SinglyLinkedList::printList(const SinglyLinkedList &pList)
{
    SNode *ptr;
    ptr = head->next;
    while (ptr != nullptr) {
        cout << ptr->data;
        ptr = ptr->next;
    }
}


int SinglyLinkedList::getLength()
{
    return length;    
}


SNode * SinglyLinkedList::getNodeAtHeadNext()
{
    return head->next;
}


SNode * SinglyLinkedList::getNodeAtHead()
{
    return head;
}