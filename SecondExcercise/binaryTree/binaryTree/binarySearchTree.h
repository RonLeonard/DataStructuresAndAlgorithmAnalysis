#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

namespace binaryTree
{

typedef struct Node
{
	Node(int _data = 0)
	{
		data = _data;
		left = nullptr;
		right = nullptr;
	}
	
	int data;
	Node* left;
	Node* right;
}StNode;


class CBinarySearchTree
{
public:
	CBinarySearchTree();
	~CBinarySearchTree();
	void insert(const int data);
	StNode* find(const int data);
	void deleteNode(const int data);
private:
	StNode *pBinarySearchTree;
	void releaseNode(StNode* p);
};

}
#endif
