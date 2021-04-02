#ifndef COMPLETE_BINARYTREE_BASEARRAY_H_
#define COMPLETE_BINARYTREE_BASEARRAY_H_

#include <vector>
using namespace std;
class CCompleteBiTreeBaseArray
{
public:
	CCompleteBiTreeBaseArray();
	~CCompleteBiTreeBaseArray();
	void putInVec(vector<int>& input);
	void preOrder();
	void inOrder();
	void postOrder();
	void printVec(const vector<int>& vec);
private:

	vector<int> ivec;
};

#endif
