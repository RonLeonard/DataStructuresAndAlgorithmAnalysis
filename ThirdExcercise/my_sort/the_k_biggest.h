#ifndef THE_K_BIGGEST_H_
#define THE_K_BIGGEST_H_

#include <vector>

using namespace std;

class CTheKBiggest
{
public:
	CTheKBiggest(const vector<int>& ivec_);
	~CTheKBiggest();
	int getTheKBiggestElem(int numK, int &theKBiggestElem);

private:
	int getTheKBiggestElemImp(int numK, int p, int r);
	int partitionImp(int p, int r);
private:

	vector<int> ivec;
};

#endif
