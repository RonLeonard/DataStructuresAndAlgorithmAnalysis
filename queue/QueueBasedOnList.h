#ifndef QUEUEBASEDONLIST_H_
#define QUEUEBASEDONLIST_H_

#include <string>

using std::string;

struct SNode {
    string data;
    SNode *next;
};

class QueueBasedOnList {

public:
    QueueBasedOnList();
    ~QueueBasedOnList();
    bool enqueue(const string& item);
    string dequeue();
private:
    int num;
    SNode *head; //队列头部
    SNode *tail; //队列的尾后元素
};



#endif