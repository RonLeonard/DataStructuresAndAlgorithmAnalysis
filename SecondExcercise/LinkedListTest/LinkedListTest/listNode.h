#ifndef _LISTNODE_H_
#define _LISTNODE_H_

#include <stdio.h>
struct stNode
{
public:
	stNode() : data(-99999), pNext(nullptr) {};
	stNode(int _data, stNode* _next) : data(_data), pNext(_next) {};
	~stNode() { };
	int data;
	stNode* pNext;
};

struct stDoubNode
{
public:
	stDoubNode() :data(-9999), pPrev(nullptr), pNext(nullptr) {};
	stDoubNode(int _data) :data(_data), pPrev(nullptr), pNext(nullptr) {};
	stDoubNode(int _data, stDoubNode* _pPrev, stDoubNode* _pNext) :data(_data), pPrev(_pPrev), pNext(_pNext) {};
	//stDoubNode(const stDoubNode& _doubNode);
	//stDoubNode& operator=(const stDoubNode& _doubNode);
	~stDoubNode() { };
	int data;
	stDoubNode* pPrev;
	stDoubNode* pNext;
};
#endif