#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

namespace binaryTree
{

typedef struct Node
{
	Node()
	{
		data = 0;
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
	StNode find(const int data);
private:
	StNode binarySearchTree = StNode();
};

}
#endif
