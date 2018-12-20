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

/************************************************
 * leetcode No.20
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * An input string is valid if:
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Note that an empty string is also considered valid.
 * 存在4种情况：
 * scanning：
 * case 1: {[}] 左右个数对称，但扫描过程中不匹配。结果：不合法
 * case 2: {}] 右括号个数多，扫描过程中出现栈为空的情况。结果：不合法
 * 
 * scan finished:
 * case 3: []{} 扫描完成后，栈为空。结果：合法
 * case 4: []{ 扫描完成后，栈不为空。结果；不合法
 * *********************************************/

bool isValid(string str)
{
    if (str == " ") {
        return true;
    }
    StackBasedOnArray strStack;
    //scanning
    for (const auto &c : str) {
        switch (c) {
            case '(':
            case '[':
            case '{':
                {
                    strStack.push(c);
                }
                break;
            case ')':
                {
                    if(strStack.pop() != '(') {
                        return false;
                    }
                }
                break;
            case ']':
                {
                    if(strStack.pop() != '[') {
                        return false;
                    }
                }
                break;
            case '}':
                {
                    if(strStack.pop() != '{') {
                        return false;
                    }
                }
                break;
            default:
                break;
        }
    }
    //scan finished
    if (strStack.pop() == ' ') {
        return true;
    }
    else {
        return false;
    }
}


int main(int argc, char *argv[])
{

    vector<string> vec = {"ren", "miao", "love", "li", "rui", "dan"};
    //StackBasedOnArray arraystack(10);
    StackBaseOnList liststack;

    for (const auto &i : vec) {
        //arraystack.push(i);
        liststack.push(i);
    }
    string str1, str2;
    // while ((str1 = arraystack.pop()) != " ")  {
    //     cout << str1 << " ";
    // }
    cout << endl;

    while ((str2 = liststack.pop()) != " ")  {
        cout << str2 << " ";
    }
    cout << endl;

    string s1("{[}]"); //case 1
    string s2("{}]"); //case 2
    string s3("[]{}"); //case 3
    string s4("[]{"); //case 4

    bool r1 = false, r2 = false, r3 = false, r4 = false;
    r1 = isValid(s1);
    r2 = isValid(s2);
    r3 = isValid(s3);
    r4 = isValid(s4);

    cout << r1 << endl;
    cout << r2 << endl;
    cout << r3 << endl;
    cout << r4 << endl;
    return 0;
}
