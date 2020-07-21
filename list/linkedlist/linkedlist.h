#define LINKEDLIST_H_
#ifdef LINKEDLIST_H_


typedef struct stNode {
	int nodeData;
	stNode* pNext = nullptr;
}stNode;


class CLinkedList {

public:
	CLinkedList();
	~CLinkedList();
	bool insertNode(int val, int idx);
	bool delNode(int nodeVal);
	bool delNode(unsigned int idx);
	stNode* findFirstPos(int val);
	stNode* findNode(unsigned int idx);
	void printLinkedListNode();
	stNode* getHeadNodePtr();
private:
	stNode* head;
	int size;
	int length;

};


#endif
