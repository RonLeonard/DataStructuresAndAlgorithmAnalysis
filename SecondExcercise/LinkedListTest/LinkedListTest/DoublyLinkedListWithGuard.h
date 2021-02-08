#ifndef DOUBLYLINKEDLISTWITHGUARD_H_
#define DOUBLYLINKEDLISTWITHGUARD_H_

#include "listNode.h"

class CDoublyLinkedListWithGuard
{
public:
	CDoublyLinkedListWithGuard();
	CDoublyLinkedListWithGuard(const CDoublyLinkedListWithGuard& _doublyLinkedListWithGuard);
	CDoublyLinkedListWithGuard& operator=(const CDoublyLinkedListWithGuard& _doublyLinkedListWithGuard);
	~CDoublyLinkedListWithGuard();
	//insert
	bool insertHead(const int& val);
	bool insertHead(const stDoubNode* pNewNode);
	bool insertTail(const int& val);
	bool insertTail(const stDoubNode* pNewNode);
	bool insertBefore(const stDoubNode* p, const int& val);
	bool insertBefore(const stDoubNode* p, const stDoubNode* pNewNode);
	bool insertAfter(const stDoubNode* p, const int& val);
	bool insertAfter(const stDoubNode* p, const stDoubNode* pNewNode);
	//delete
	bool deleteNode(const int& val);
	bool deleteNode(const stDoubNode* p);
	//find
	stDoubNode* findByVal(const int& val);
	stDoubNode* findByIdx(const int& idx);

	void printLinkedList() const;
private:
	stDoubNode* m_pHead = new stDoubNode();
};


#endif
