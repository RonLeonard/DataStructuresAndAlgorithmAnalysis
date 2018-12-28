#include <vector>
#include <iostream>
#include "QueueBasedOnArray.h"


using std::vector;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    QueueBasedOnArray array_queue(3);
    vector<string> vec1 = {"ren", "miao","leonard", "ron"};
    for (auto i : vec1) {
        if (!array_queue.enqueue(i))
            cout << "array_queue is full." << endl;
    }
    
    vector<string> vec2;
    string item;
    for (int i = 0; i < 4; i++) {   
        item = array_queue.dequeue();
        if (item != " ")
            vec2.push_back(item);
        else
            cout << "array_queue is null." << endl;
    }

    cout << endl;
    for (auto i : vec2) {
        cout << i << " ";
    }
    cout << endl;

}