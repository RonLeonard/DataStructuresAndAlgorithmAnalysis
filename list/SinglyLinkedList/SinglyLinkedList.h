#ifndef _SINGLYLINKEDLIST_H_
#define _SINGLYLINKEDLIST_H_

struct SNode {
    char data;
    SNode *next;
};

class SinglyLinkedList {

public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    bool isEmpty();
    void insertElemAtHead(char elem);
    void insertElemAtTail(char elem);
    void deleteTailNode();
    void printList(const SinglyLinkedList &pList);
    int getLength();
    SNode * getNodeAtHeadNext();
    SNode * getNodeAtHead();

private:
    int length;
    SNode *head;
    SNode *tail;
};

#endif