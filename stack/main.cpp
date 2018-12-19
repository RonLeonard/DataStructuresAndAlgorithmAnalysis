#include <iostream>
#include <vector>
#include <string>
#include "StackBasedOnArray.h"
#include "StackBasedOnList.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;


int main(int argc, char *argv[])
{
    vector<string> vec = {"ren", "miao", "love", "li", "rui", "dan"};
    StackBasedOnArray arraystack(10);
    StackBaseOnList liststack;

    for (const auto &i : vec) {
        arraystack.push(i);
        liststack.push(i);
    }
    string str1, str2;
    while ((str1 = arraystack.pop()) != " ")  {
        cout << str1 << " ";
    }
    cout << endl;

    while ((str2 = liststack.pop()) != " ")  {
        cout << str2 << " ";
    }
    cout << endl;
    return 0;
}
