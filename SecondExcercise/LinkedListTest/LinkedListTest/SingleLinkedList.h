#ifndef __SINGLELINKEDLIST_H__
#define __SINGLELINKEDLIST_H__

typedef struct Node
{
	struct Node() : data(0), pNext(nullptr) {};
	struct Node(int _data, stNode* _next) : data(_data), pNext(_next) {};
	int data;
	struct Node* pNext;
}stNode;

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
	CSingleLinkedList& operator=(const CSingleLinkedList& singleLinkList);
	bool insertHead(const int val);
	bool insertHead(stNode* pNode);
	bool insertTail(const int val);
	bool insertTail(stNode* pNode);
	bool insertBefore(stNode* p, const int val);
	bool insertBefore(stNode* p, stNode* pNewNode);
	bool insertAfter(stNode* p, const int val);
	bool insertAfter(stNode* p, stNode* pNewNode);
	bool deleteNode(const int val);
	bool deleteNode(stNode* pNewNode);
	stNode* find(const int val);
	uint getCount(stNode* pHead) const;
	void printLinkedList(const stNode* pHead) const;
private:
	stNode* m_pHead;
	
};

#endif