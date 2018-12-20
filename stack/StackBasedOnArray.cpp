#include <iostream>
#include "StackBasedOnArray.h"

using std::cout;
using std::endl;

StackBasedOnArray::StackBasedOnArray()
{
    items = new char[10];
    m_count = 0;
    m_num = 10;
}


StackBasedOnArray::StackBasedOnArray(int n)
{
    items = new char[n];
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


bool StackBasedOnArray::push(char item)
{
    if (m_count == m_num) {
        m_num *= 2; 
        char *tmp = new char[m_num];
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


char StackBasedOnArray::pop()
{
    if (m_count == 0) {
        return ' ';
    }
    m_count--;
    char tmp = items[m_count];
    return tmp;
}
