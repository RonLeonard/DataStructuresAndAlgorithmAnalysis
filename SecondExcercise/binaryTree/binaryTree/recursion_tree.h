#ifndef RECURSION_TREE_H
#define RECURSION_TREE_H

#include <vector>

using namespace std;

class CRecursionTree
{
public:
	void printRermutations(int n , int k);
	void putInElem(int ele);
private:
	vector<int> ivec;
};

#endif
