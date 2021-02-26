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
	bool insertHead(stDoubNode* pNewNode);
	bool insertTail(const int& val);
	bool insertTail(stDoubNode* pNewNode);
	bool insertBefore(stDoubNode* p, const int& val);
	bool insertBefore(stDoubNode* p, stDoubNode* pNewNode);
	bool insertAfter(stDoubNode* p,  const int& val);
	bool insertAfter(stDoubNode* p, stDoubNode* pNewNode);
	//delete
	bool deleteNode(const int& val);
	bool deleteNode(const stDoubNode* p);
	//find
	stDoubNode* findByVal(const int& val);
	stDoubNode* findByIdx(const int& idx);

	void printLinkedList() const;
private:
	stDoubNode* m_pHead = new stDoubNode();
	stDoubNode* m_pTail = new stDoubNode();
};


#endif
