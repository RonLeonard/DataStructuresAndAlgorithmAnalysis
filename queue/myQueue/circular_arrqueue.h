#ifndef CIRCULAR_QUEUE_H

#define CIRCULAR_QUEUE_H


class CCircularArrQueue
{
public:
	CCircularArrQueue(int _n);
	~CCircularArrQueue();
	bool enqueue(int val);
	int dequeue();
	void printElemOfMemory();

private:
	int n = 0;
	int count = 0;
	int head = 0;
	int tail = 0;
	int *pArr;
};


#endif

