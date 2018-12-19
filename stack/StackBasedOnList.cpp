#include <iostream>
#include "StackBasedOnList.h"

using std::cout;
using std::endl;



StackBaseOnList::StackBaseOnList()
{
    head = new SNode();
    head->data = " ";
    head->next = nullptr;
    count = 0;
}


StackBaseOnList::~StackBaseOnList()
{
    SNode *ptr;
    while (head) {
        ptr = head->next;
        delete head;
        head = ptr;
    }
}



bool StackBaseOnList::push(string item)
{
    SNode *ptr = new SNode();
    ptr->data = item;
    ptr->next = nullptr;

    SNode *tmp = head;
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = ptr;
    ++count;

}


string StackBaseOnList::pop()
{
    SNode *ptr = head;
    if (!(head->next)) {
        //cout << "The stack is null." <<endl;
        return " ";
    }

    while (ptr->next->next) {
        ptr = ptr->next;
    }

    string tmp = ptr->next->data; //保存尾元素的值

    delete ptr->next; //删除尾元素
    ptr->next = nullptr; //设置新的尾元素
    --count;
    return tmp;
}