#include "QueueBasedOnList.h"

QueueBasedOnList::QueueBasedOnList()
{
    head = new SNode();
    head->data = " ";
    head->next = nullptr;
    tail = head;
    num = 0;
}


~QueueBasedOnList::QueueBasedOnList()
{
    if (!head) {
        SNode *tmp = head;
        head = head->next;
        delete tmp;
    }
}


void QueueBasedOnList::enqueue(const string& item)
{
    if (tail->data == " ") {
        tail->data = item;
    }
    else {
        SNode *tmp = new SNode();
        tail->next = tmp;
        tail = tail->next;

        tail->data = item;
        tail->next = nullptr;
    }
}


string QueueBasedOnList::dequeue()
{
    if (head->data == " ") {
        return "";
    }
    else {
        string tmp = head->data;
        head = head->next;
        return tmp;
    }
}