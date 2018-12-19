#include <iostream>
#include "StackBasedOnArray.h"

using std::cout;
using std::endl;

StackBasedOnArray::StackBasedOnArray()
{
    items = new string[10];
    m_count = 0;
    m_num = 10;
}


StackBasedOnArray::StackBasedOnArray(int n)
{
    items = new string[n];
    if (!items) {
        cout << "allocate memory failed!" << endl;
    }
    m_count = 0;
    m_num = n;

}


StackBasedOnArray::~StackBasedOnArray()
{
    m_count = 0;
    m_num = 0;
    if (items) {
        delete [] items;
        items = nullptr;
    }
}


bool StackBasedOnArray::push(string item)
{
    if (m_count == m_num) {
        m_num *= 2; 
        string *tmp = new string[m_num];
        for (int i = 0; i != m_num; i++) {
            tmp[i] = items[i];
        }

        delete [] items;
        items = tmp;
    }
    
   
    items[m_count] = item;
    ++m_count;

    return true;
}


string StackBasedOnArray::pop()
{
    if (m_count == 0) {
        return " ";
    }
    m_count--;
    string tmp = items[m_count];
    return tmp;
}
