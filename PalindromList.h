#ifndef _PALINDROMLIST_H_
#define _PALINDROMLIST_H_

struct SNode {
    char data;
    SNode *next;
};

class PalindromList {

public:
    PalindromList();
    ~PalindromList();
    bool isEmpty();
    void insertElemAtHead(char elem);
    void insertElemAtTail(char elem);
    void deleteTailNode();
    void printList(const PalindromList &pList);
    int getLength();
    SNode * getNodeAtHeadNext();

private:
    int length;
    SNode *head;
    SNode *tail;
};

#endif