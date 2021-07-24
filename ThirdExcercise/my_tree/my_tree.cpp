#include <stdio.h>

#include "my_tree.h"


CBinaryTree::CBinaryTree(): m_pRoot(nullptr)
{

}


CBinaryTree::~CBinaryTree()
{

}


bool CBinaryTree::create_binaryTree()
{
	bool ret = false;
	ret = create_binaryTreeImp(m_pRoot);
	return ret;
}


bool CBinaryTree::create_binaryTreeImp(shared_ptr<TreeNode> &pTreeNode)
{
	bool ret = true;
	int a = 0;
	printf("\r\n输入节点数值((当输入为100时，当前节点创建完成))):");
	scanf("%d", &a);
	if (a == 100)
	{
		pTreeNode = nullptr;
		return ret;
	}
	else
	{
		//*ppTreeNode = new TreeNode(a);
		pTreeNode = make_shared<TreeNode>(a);
		if (!pTreeNode)
		{
			printf("new ppTreeNode failed\n");
			return false;
		}
		printf("\r\n create %d's left child:", a);
		create_binaryTreeImp(pTreeNode->left);
		printf("\r\n create %d's right child:", a);
		create_binaryTreeImp(pTreeNode->right);
	}
	return ret;
}





void CBinaryTree::preOrder()
{
	preOrderImp(m_pRoot);
	printf("\n");
	return;
}


void CBinaryTree::preOrderImp(shared_ptr<TreeNode>& pTreeNode)
{
	if (!pTreeNode)
	{
		return;
	}
	printf("%d ", pTreeNode->data);
	preOrderImp(pTreeNode->left);
	preOrderImp(pTreeNode->right);
	return;
}