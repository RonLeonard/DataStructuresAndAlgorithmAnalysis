#ifndef _MY_ARRAY_QUEUE_H
#define _MY_ARRAY_QUEUE_H


class CArrayQueue
{
public:
	CArrayQueue(int n_);
	~CArrayQueue();
	bool enqueue(int val);
	int dequeue();

private:
	int count = 0;
	int n = 0;
	int* pArray;

};


#endif
