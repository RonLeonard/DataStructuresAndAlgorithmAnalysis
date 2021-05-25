#ifndef SINGLE_LINKEDLIST_H
#define SINGLE_LINKEDLIST_H


typedef struct Node {
	struct Node() : data(0), next(nullptr)
	{

	}
	int data;
	struct Node* next;
} StNode;


class CSingleLinkedList
{
public:
	CSingleLinkedList();
	~CSingleLinkedList();
	StNode* getHead();
	StNode* findVal(const int &val);
	bool delVal(const int &val);
	bool delNode(const StNode* pNode);
	bool insertBefore(const StNode* pNode, const int& val);
	bool insertAfter(const StNode* pNode, const int& val);
	bool insertHead(const int &val);
	bool insertTail(const int& val);

	void inverseLinkedList();

	StNode* findMiddleNode();
	void delLastKth(const int &k);
	void printSingleLinkedList();

private:
	StNode* head;
};


#endif
