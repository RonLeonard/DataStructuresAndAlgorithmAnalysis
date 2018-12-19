#ifndef STACKBASEDONARRAY_H_
#define STACKBASEDONARRAY_H_
#include <string>
using std::string;

class StackBasedOnArray {

public:
    StackBasedOnArray();
    StackBasedOnArray(int n);
    ~StackBasedOnArray();
    bool push(string item);
    string pop();
private:
    string *items;
    int m_count; //栈中元素个数
    int m_num;  //栈的大小
};

#endif