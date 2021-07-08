#ifndef THE_K_BIGGEST_H_
#define THE_K_BIGGEST_H_

#include <vector>

using namespace std;

class CTheKBiggest
{
public:
	CTheKBiggest(int numK_, const vector<int>& ivec_) : numK(numK_), ivec(ivec_);
	~CTheKBiggest();
	int getTheKBiggestElem(int numK, int &theKBiggestElem);
private:

	vector<int> ivec;
};

#endif
