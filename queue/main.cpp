#include <vector>
#include <iostream>
#include "QueueBasedOnArray.h"
#include "QueueBasedOnList.h"

using std::vector;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    QueueBasedOnArray array_queue(3);
    QueueBasedOnList list_queue;
    vector<string> vec1 = {"ren", "miao","leonard", "ron"};

    for (auto i : vec1) {
        if (!array_queue.enqueue(i))
            cout << "array_queue is full." << endl;
    }
    for (auto i : vec1) {
        list_queue.enqueue(i);
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
    for (auto i : vec2) {
        cout << i << " ";
    }
    cout << endl;


    vector<string> vec3;
    for (int i = 0; i < 4; i++) {   
        item = list_queue.dequeue();
        if (item != " ")
            vec3.push_back(item);
        else
            cout << "list_queue is null." << endl;
    }
    for (auto i : vec3) {
        cout << i << " ";
    }
    cout << endl;

}