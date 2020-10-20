#ifndef _SINGLELINKEDLIST_NOGUARD_H
#define _SINGLELINKEDLIST_NOGUARD_H

typedef struct Node
{
	int data = 0;
	struct Node *pNextNode = nullptr;
}stNode;

class CSingleLinkedList_NoGuard
{
public:
	CSingleLinkedList_NoGuard();
	~CSingleLinkedList_NoGuard();

	bool insertStNode(int idx, int data);
	bool deleteStNode(int idx);
	stNode* findStNode(int idx);
	void printStNode();
public:
	stNode* head;
	int size;
};


#endif
