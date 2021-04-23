#include "completeBinaryTree_baseArray.h"
#include "recursion_tree.h"

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



//test recurison tree
void test_recurison_tree()
{
	CRecursionTree recursionTree;
	recursionTree.putInElem(1);
	recursionTree.putInElem(2);
	recursionTree.putInElem(3);
	recursionTree.putInElem(4);
	recursionTree.printRermutations(4, 4);
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
	printf("\ntest PostOrder:\n");
	test_CompleteBiTree_postOrder(&biTree);
	printf("\ntest recursion tree:\n");
	test_recurison_tree();
}