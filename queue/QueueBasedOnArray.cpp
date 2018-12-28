#include <iostream>
#include "QueueBasedOnArray.h"


using std::cout;
using std::cin;
using std::endl;


QueueBasedOnArray::QueueBasedOnArray() 
{
    items = new string[10];
    capacity = 10;
    head = tail = 0;
}


QueueBasedOnArray::QueueBasedOnArray(int n) : capacity(n)
{
    items = new string[n];
    head = tail = 0;
}
   
   
QueueBasedOnArray::~QueueBasedOnArray()
{
    capacity = 0;
    head = tail = 0;
    if (items) {
        delete [] items;
        items = nullptr;
    }
}
    
    
bool QueueBasedOnArray::enqueue(const string& item)
{
    if (tail == capacity) { 
        if (head == 0) {//队列已满
             return false;
        }
        else { //数据整体搬移, writed by myself
/*            int n = tail -head;
            for (int i = 0; i < n; i++) {
                items[i] = items[head + i];
            }
            head = 0;
            tail = n;
*/
            //数据整体搬移，writed by wangzheng
            for (int i = head; i < tail; i++) {
                items[i - head] = items[i];
            }
            tail -= head;
            head = 0;
            
        }  
    }
    
    items[tail] = item;
    ++tail;
    return true;
}
    
    
string QueueBasedOnArray::dequeue()
{
    if (head == tail) {
        return " ";
    }
    string tmp = items[head];
    ++head;
    return tmp;
}

