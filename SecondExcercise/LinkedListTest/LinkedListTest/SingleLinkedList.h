#ifndef __SINGLELINKEDLIST_H__
#define __SINGLELINKEDLIST_H__

#include "listNode.h"

//typefef struct Node stNode;
typedef unsigned int uint;

class CSingleLinkedList
{
public:
	CSingleLinkedList();
	//copy constructer
	CSingleLinkedList(const CSingleLinkedList& singleLinkList);
	~CSingleLinkedList();
	//copy assignment operator
	//CSingleLinkedList& operator=(const CSingleLinkedList& singleLinkList);
	bool insertHead(const int val);
	bool insertHead(stNode* pNode);
	bool insertTail(const int val);
	bool insertTail(stNode* pNode);
	bool insertBefore(stNode* p, const int val);
	bool insertBefore(stNode* p, stNode* pNewNode);
	bool insertAfter(stNode* p, const int val);
	bool insertAfter(stNode* p, stNode* pNewNode);
	bool deleteNode(const int val);
	bool deleteNode(stNode* pNode);
	stNode* findByVal(const int &val);
	stNode* findByIndex(const uint & idx);
	void printLinkedList() const;
private:
	stNode* m_pHead;
	
};

#endif