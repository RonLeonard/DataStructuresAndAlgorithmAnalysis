#ifndef _LISTNODE_H_
#define _LISTNODE_H_

#include <stdio.h>
class stNode
{
public:
	stNode() : data(-99999), pNext(nullptr) {};
	stNode(int _data, stNode* _next) : data(_data), pNext(_next) {};
	~stNode() { };
	int data;
	stNode* pNext;
};


#endif