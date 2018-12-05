#include <string>
#include <iostream>
#include "SinglyLinkedList/SinglyLinkedList.h"

using std::string;
using std::cout;
using std::endl;

bool isPalindromeList(SinglyLinkedList &rList)
{
    if (rList.getNodeAtHead() == nullptr) 
        return false;

    SNode *slow, *fast;
    slow = rList.getNodeAtHead();
    fast = rList.getNodeAtHead();

    bool even = true;
    bool isPalindrome = false;

/*
    while (fast != nullptr) { //寻找链表的中点
  
        if (fast->next == nullptr) { //如果是偶数个结点，则移动n次后就到达了尾结点
            even = true;
            break;
        }  
        else if (fast->next->next == nullptr) { //如果是奇数个结点，则移动n次后就到达了倒数第二个结点
            even = false;
            break;
        }
        else {
            fast = fast->next->next;
            slow = slow->next;
        }
    }
*/
   
    while (fast && fast->next) { //fast移动n次，如果fast->next为nullptr，则说明为even；如果fast为nullptr，则说明为odd.
        fast = fast->next->next;
        slow = slow->next;
    }
    if (!fast) {
        even = false;
    }
    

    SNode *mid = slow;
    SNode *midNextSaved = slow->next;
    SNode *ptr1 = new SNode();
    SNode *ptr2 = new SNode();
    SNode *ptr = new SNode();
 
    if (even) {
        ptr2 = slow->next;
    }
    else {
        ptr2 = slow->next->next;
    }
        
    
    while (ptr2 != nullptr) { //从中点的后一个结点开始逆序后半部分链表
        ptr = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr;
    }
    mid->next = nullptr;


    SNode *tmp = new SNode();
    tmp = rList.getNodeAtHeadNext();
    ptr2 = ptr1; //保存后半部分的head节点
    while (tmp != nullptr) { //判断是否是前后半部分是否是对称

        if (tmp->data == ptr1->data) {
            tmp = tmp->next;
            ptr1 = ptr1->next;
        }
        else {
            isPalindrome = false;
            break;
        }
    }
    if (tmp == nullptr)  
        isPalindrome = true;

    delete tmp;    


    /***还原链表**/
     ptr1 = nullptr;
     while (ptr2 != nullptr) { //从中点的后一个结点开始逆序后半部分链表
        ptr = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr;
    }


    if (even) 
        slow->next = ptr1;
    else
        slow->next = midNextSaved;

    delete ptr1;
    delete ptr2;
    delete ptr;
    return isPalindrome;

}



int main(int argc, char *argv[])
{
    string str("levell");
    SinglyLinkedList ls;
    for (auto i : str) 
        ls.insertElemAtTail(i);
    
    ls.printList(ls);
    cout << endl;

    bool res = isPalindromeList(ls);
    cout << "res = " << res << endl;

    return 0;
}