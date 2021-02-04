#ifndef _SINGLELINKEDLISTWITHGUARD_H_
#define _SINGLELINKEDLISTWITHGUARD_H_

#include "listNode.h"

class CSingleLinkedListWithGuard
{
public:
	CSingleLinkedListWithGuard();
	//copy constructor
	//CSingleLinkedListWithGuard(const CSingleLinkedListWithGuard& p);
	~CSingleLinkedListWithGuard();
	//copy assignment operator
	//CSingleLinkedListWithGuard& operator=(const CSingleLinkedListWithGuard& p);

	//insert
	bool insertHead(const int data);
	bool insertHead(stNode* pNode);
	bool insertTail(const int data);
	bool insertTail(stNode* pNode);
	bool insertBefore(const int data);
	bool insertBefore(stNode* pNode);
	bool insertAfter(const int data);
	bool insertAfter(stNode* pNode);
	//delete
	bool deleteNode(const int val);
	bool deleteNode(stNode* pNode);
	//find
	stNode* findByVal(const int& val);
	stNode* findByIndex(const unsigned int& idx);
	void printLinkedList() const;

private:
	stNode* m_pHead = new stNode();
	
};

#endif
