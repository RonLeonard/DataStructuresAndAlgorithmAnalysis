#define _ARRAYSTACK_TEST
#ifndef _ARRAYSTACK_TEST
#include <iostream>
#include "arrayStack.h"


int main(int argc, char** argv)
{
	CArrayStack* pArrStack = new CArrayStack(5);

	pArrStack->push(0);
	pArrStack->push(1);
	pArrStack->push(2);
	pArrStack->push(3);
	pArrStack->printElem();

	
	int ret = pArrStack->pop();
	std::cout << ret << std::endl;
	pArrStack->printElem();
	system("pause");
	return 0;
}

#endif