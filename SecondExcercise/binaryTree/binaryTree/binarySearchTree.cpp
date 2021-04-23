#include "binarySearchTree.h"

namespace binaryTree
{

CBinarySearchTree::CBinarySearchTree() : pBinarySearchTree(nullptr)
{

}


CBinarySearchTree::~CBinarySearchTree()
{
	if (pBinarySearchTree != nullptr)
		releaseNode(pBinarySearchTree);
}


void CBinarySearchTree::releaseNode(StNode* p)
{
	if (p->left != nullptr)
		releaseNode(p->left);
	if (p->right != nullptr)
		releaseNode(p->right);
	delete p;
	p = nullptr;
}


void CBinarySearchTree::insert(const int data)
{
	if (pBinarySearchTree == nullptr)
	{
		pBinarySearchTree = new StNode();
		pBinarySearchTree->data = data;
		return;
	}
	
	StNode* tmp = pBinarySearchTree;
	while (tmp != nullptr)
	{
		if (data < tmp->data)
		{
			if (tmp->left == nullptr)
			{
				tmp->left = new StNode(data);
				return;
			}
			else
				tmp = tmp->left;
		}
		else if (data > tmp->data)
		{
			if (tmp->right == nullptr)
			{
				tmp->right = new StNode(data);
				return;
			}
			else
				tmp = tmp->right;
		}
	}
}


StNode* CBinarySearchTree::find(const int data)
{
	StNode* tmp = pBinarySearchTree;
	while (tmp != nullptr)
	{
		if (data == tmp->data)
			return tmp;
		else if (data < tmp->data)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	return nullptr;
}


void CBinarySearchTree::deleteNode(const int data)
{
	StNode* p = pBinarySearchTree;
	StNode* pp = nullptr;
	while (p != nullptr && p->data != data)
	{
		pp = p;
		if (p->data < data)
			p = p->right;
		else
			p = p->left;
	}
	if (p == nullptr)// no found
		return;
	
	if (p->left != nullptr && p->right != nullptr)
	{
		StNode* minP = p->right;
		StNode* minPP = p;
		while (minP->left != nullptr)
		{
			minPP = minP;
			minP = minP->left;
		}
		p->data = minP->data;
		p = minP;
		pp = minPP;
	}

	StNode* child = nullptr;
	if (p->left != nullptr) child = p->left;
	else if (p->right != nullptr) child = p->right;
	else child = nullptr;

	if (pp == nullptr) pBinarySearchTree = child;
	else if (pp->left == p) pp->left = child;
	else pp->right == child;
}

}