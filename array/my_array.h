#ifndef _MY_ARRAY
#define _MY_ARRAY

class CMyArray
{
public:
	CMyArray(int size_ = 6);
	bool getValOfSpecifiedIdx(int idx, int &val);
	bool insertElem(int val, int idx);
	bool deleteElemOfSpecifiedIdx(int idx);
	void printElem();
	int getLength();
	~CMyArray();
private:
	int length;
	int size;
	int *pArr;
};

#endif
