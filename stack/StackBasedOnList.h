#ifndef STACKBASEDONLIST_H_
#define STACKBASEDONLIST_H_

#include <string>

using std::string;

struct SNode {
    string data;
    SNode *next;
};

class StackBaseOnList {

public:
    StackBaseOnList();
    ~StackBaseOnList();

    bool push(string item);
    string pop();

private:
    SNode *head;
    int count; //栈中已保存元素的个数
    
};


#endif