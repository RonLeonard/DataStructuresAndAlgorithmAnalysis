#ifndef _ARRAY_STACK
#define _ARRAY_STACK


class CArrayStack
{
public:
	CArrayStack(int n);
	bool push(int val);
	int pop();
	int getTopElem();
	~CArrayStack();
	void printElem();
	int getCountOfArrayStack();
private:
	
	int *items;
	int count;
	int n;
};
#endif
