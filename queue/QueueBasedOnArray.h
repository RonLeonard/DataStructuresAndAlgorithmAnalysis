#ifndef QUEUEBASEDONARRAY_H_
#define QUEUEBASEDONARRAY_H_

#include <string>

using std::string;


class QueueBasedOnArray {

public:
    QueueBasedOnArray();
    QueueBasedOnArray(int n);
    ~QueueBasedOnArray();
    bool enqueue(const string& item);
    string dequeue();
private:
    string *items = nullptr;
    int capacity;
    int head; //队列头元素的位置
    int tail; //队列的尾后元素的位置
};



#endif