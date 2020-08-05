#ifndef _MY_ARRAY
#define _MY_ARRAY

class CMyArray
{
public:
	CMyArray();
	bool getValOfSpecifiedIdx(int idx, int &val);
	bool insertElem(int val, int idx);
	bool deleteElemOfSpecifiedIdx(int val);
	~CMyArray();
private:
	int length;
	int size;
	int *pArr;
};

#endif
