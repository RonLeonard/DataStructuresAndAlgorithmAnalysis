#define _MATCHING_OPERATION
#ifndef _MATCHING_OPERATION

#include <iostream>
#include "arrayStack.h"


int main(int argc, int argv)
{
	//std::string str = "{[]}";
	std::string str = "{[(])}";
	CArrayStack* pCArrayStack = new CArrayStack(10);
	bool flag = false;
	for (auto c : str)
	{
		if (c == '{' || c == '[' || c == '(')
		{
			int i = c;
			pCArrayStack->push(c);
		}
		else
		{
			int val = pCArrayStack->getTopElem();
			if (c ==  '}' && (val == 40))
			{
				pCArrayStack->pop();
				continue;
			}
			else if (c == ']' && (val == 91))
			{
				pCArrayStack->pop();
				continue;
			}
			else if (c == '}' && (val == 123))
			{
				pCArrayStack->pop();
				continue;
			}
			else
			{
				std::cout << "the bracket is not match." << std::endl;
				flag = true;
				break;
			}
		}
	}

	if (flag == false)
	{
		int count = pCArrayStack->getCountOfArrayStack();
		if (count == 0)
		{
			std::cout << "the bracket is match." << std::endl;
		}
		else
		{
			std::cout << "the bracket is not match." << std::endl;
		}
	}

	return 0;
}


#endif