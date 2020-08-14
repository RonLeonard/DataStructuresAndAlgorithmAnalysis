//#define BROWER_FORWARD_BACKWARD
#ifndef BROWER_FORWARD_BACKWARD

#include <iostream>
#include <string>
#include "arrayStack.h"

using namespace std;

int main(int argc, char** argv)
{
	string input;
	char c;
	cout << "input the number or f means forward or b means backward:" << endl;
	
	CArrayStack* pArrayStack1 = new CArrayStack(10);
	CArrayStack* pArrayStack2 = new CArrayStack(10);
	while ((cin >> c) && (c != EOF))
	{
		if ((c >= '0' && c <= '9') || c == 'f' || c == 'b')
		{
			if ((c >= '0') && (c <= '9'))
			{
				if (pArrayStack2->getCountOfArrayStack() != 0)
				{
					pArrayStack2->clearStack();
				}
				pArrayStack1->push(atoi(&c));
				cout << "the element of stack1 is:" << endl;
				pArrayStack1->printElem();
				cout << "the element of stack2 is:" << endl;
				pArrayStack2->printElem();
			}
			else if (c == 'b')//backward
			{
				int elem = pArrayStack1->pop();
				if (elem != -1)
				{
					pArrayStack2->push(elem);
					cout << "the element of stack1 is:" << endl;
					pArrayStack1->printElem();
					cout << "the element of stack2 is:" << endl;
					pArrayStack2->printElem();
				}
				else
				{
					cout << "no element in stack1" << endl;
				}
			}
			else//forward
			{
				int elem = pArrayStack2->pop();
				if (elem != -1)
				{
					pArrayStack1->push(elem);
					cout << "the element of stack1 is:" << endl;
					pArrayStack1->printElem();
					cout << "the element of stack2 is:" << endl;
					pArrayStack2->printElem();
				}
				else
				{
					cout << "no element in stack2" << endl;
				}
			}

		}
		else
		{
			cout << "please input valid character base on the hint " << endl;
		}
	}


	delete pArrayStack1;
	delete pArrayStack2;
	pArrayStack1 = nullptr;
	pArrayStack2 = nullptr;
	system("pause");
	return 0;
}



#endif