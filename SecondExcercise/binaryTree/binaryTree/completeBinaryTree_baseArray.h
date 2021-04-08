#ifndef COMPLETE_BINARYTREE_BASEARRAY_H_
#define COMPLETE_BINARYTREE_BASEARRAY_H_

#include <vector>
using namespace std;
class CCompleteBiTreeBaseArray
{
public:
	CCompleteBiTreeBaseArray();
	~CCompleteBiTreeBaseArray();
	void putInVec(const int& input);
	void preOrder();
	void preOrder_imp(const int idx);
	void inOrder();
	void inOrder_imp(const int idx);
	void postOrder();
	void postOrder_imp(const int idx);
	void printVec();
private:

	vector<int> ivec;
};

#endif
