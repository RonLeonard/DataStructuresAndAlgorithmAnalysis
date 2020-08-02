#ifndef GUARD_LINKED_LIST_H_
#define GUARD_LINKED_LIST_H_


typedef struct stListNode {
	int data;
	stListNode *pNext = nullptr;
} stListNode;



class CGuardLinkedList
{

public:
	CGuardLinkedList();
	~CGuardLinkedList();
	stListNode* findFirstPos(int val);
	stListNode* findVal(unsigned int idx);

	bool delNode(int val);
	bool delNode(unsigned int idx);

	bool insertNode(stListNode* pStListNode, unsigned int idx);
	void printLinkedList();
private:
	unsigned int mSize;
	stListNode* head;
};



#endif