#pragma once
#include <memory>

using namespace std;
struct TreeNode
{
	TreeNode(int data_) : data(data_), left(nullptr), right(nullptr) {}
	int data;
	shared_ptr<TreeNode> left;
	shared_ptr<TreeNode> right;
};



class CBinaryTree
{

public:
	CBinaryTree();
	~CBinaryTree();
	bool create_binaryTree();
	void preOrder();
private:
	bool create_binaryTreeImp(shared_ptr<TreeNode>& pTreeNode);
	void preOrderImp(shared_ptr<TreeNode>& pTreeNode);

private:
	shared_ptr<TreeNode> m_pRoot;
};





