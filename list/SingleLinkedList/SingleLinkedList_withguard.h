#ifndef _SINGLELINKEDLIST_WITHGUARD_H
#define _SINGLELINKEDLIST_WITHGUARD_H

typedef struct Node
{
	int data = 0;
	struct Node* pNextNode = nullptr;
}stNode;

class CSingleLinkedList_WithGuard
{
public:
	CSingleLinkedList_WithGuard();
	~CSingleLinkedList_WithGuard();

	bool insertStNode(int idx, int data);
	bool deleteStNode(int idx);
	bool deleteStNode(stNode* specifiedIdx);
	stNode* findStNodeByIdx(int idx);
	stNode* findStNodeByVal(int val);
	void printStNode();
	stNode* getHeadNode();
	void reverseLinkedList();
public:
	stNode* head;
	int size;
};
#endif