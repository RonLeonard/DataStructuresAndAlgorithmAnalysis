#include "completeBinaryTree_baseArray.h"


void test_CompleteBiTree_PreOrder(CCompleteBiTreeBaseArray *pBiTree)
{
	pBiTree->preOrder();
}



void test_CompleteBiTree_InOrder(CCompleteBiTreeBaseArray* pBiTree)
{
	pBiTree->inOrder();
}


void test_CompleteBiTree_postOrder(CCompleteBiTreeBaseArray* pBiTree)
{
	pBiTree->postOrder();
}


int main(int argc, char** argv)
{
	CCompleteBiTreeBaseArray biTree;
	biTree.putInVec(6);
	biTree.putInVec(4);
	biTree.putInVec(5);
	biTree.putInVec(3);
	biTree.putInVec(2);
	biTree.putInVec(1);
	biTree.putInVec(8);
	biTree.printVec();
	printf("test preOrder:\n");
	test_CompleteBiTree_PreOrder(&biTree);
	printf("\ntest InOrder:\n");
	test_CompleteBiTree_InOrder(&biTree);
	printf("test PostOrder:\n");
	test_CompleteBiTree_postOrder(&biTree);
}