#ifndef __SINGLELINKEDLIST_H__
#define __SINGLELINKEDLIST_H__

typedef struct Node
{
	int data;
	struct Node* pNext;
}stNode;

//typefef struct Node stNode;


class CSingleLinkedList
{
public:
	CSingleLinkedList();
	//copy constructer
	CSingleLinkedList(const CSingleLinkedList& singleLinkList);
	~CSingleLinkedList();
	//copy assignment operator
	CSingleLinkedList& operator=(const CSingleLinkedList& singleLinkList);
	bool insert(const int val, const unsigned int pos);
	bool deleteNode(const int val);
	stNode* find(const int val);
	int getCount(const stNode* pHead) const;
	void printLinkedList(const stNode* pHead) const;
private:
	stNode* pHead;
};

#endif