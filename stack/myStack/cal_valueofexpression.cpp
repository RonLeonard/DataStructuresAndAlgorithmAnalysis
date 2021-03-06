#define CAL_VALUEOFEXPRESSION
#ifndef CAL_VALUEOFEXPRESSION

#include <iostream>
#include "arrayStack.h"

int operatorVal(int v1, int v2, int oper)
{
	int ret = 0;
	switch (oper)
	{
		case 0://'+'
		{
			ret = v1 + v2;
			break;
		}
		case 1:// '-'
		{
			ret = v1 - v2;
			break;
		}
		case 2: //'*'
		{
			ret = v1 * v2;
			break;
		}
		case 3://'/'
		{
			ret = v1 / v2;
			break;
		}
		default:
			break;
	}
	return ret;
}
int main(int argc, char* argv)
{
	int oper[4] = { '+', '-', '*', '/' };
	int pri[4] = { 1, 1, 2, 2 };
	//std::string exp = "5-3*1+2";
	std::string exp = "5-3*2/1";
	CArrayStack *pArrStack_Int = new CArrayStack(10);
	CArrayStack *pArrStack_opreator = new CArrayStack(5);

	for (auto c : exp)
	{
		if (c == '+' || c == '-' ||
			c == '*' || c == '/')
		{
			int idx = 0;
			int elem = 0;
			int idx_pri = 0;
			int elem_pri = 0;
			for (int i = 0; i < 4; i++)
			{
				if (c == oper[i])
					idx = i;					
			}
			idx_pri = pri[idx];//get the priority of idx
  			
			if (pArrStack_opreator->getTopElem() == -1)
			{
				pArrStack_opreator->push(idx);
			}
			else
			{
				while (pArrStack_opreator->getTopElem() != -1)
				{
					elem = pArrStack_opreator->getTopElem();
					elem_pri = pri[elem];//get the priority of elem
					if (idx_pri <= elem_pri)// the priority of idx is not higher than elem's
					{
						int v2 = pArrStack_Int->pop();
						int v1 = pArrStack_Int->pop();
						elem = pArrStack_opreator->pop();
						int ret = operatorVal(v1, v2, elem);
						pArrStack_Int->push(ret);
					}
					else
						break;
				}
				pArrStack_opreator->push(idx);
			}
		}
		else//push value of expression
		{
			pArrStack_Int->push(atoi(&c));
		}
	}


	int len = pArrStack_opreator->getCountOfArrayStack();
	for (int i = 0; i < len; i++)
	{
		int op = pArrStack_opreator->pop();
		int v2 = pArrStack_Int->pop();
		int v1 = pArrStack_Int->pop();
		int ret = operatorVal(v1, v2, op);
		pArrStack_Int->push(ret);
	}


	int val = pArrStack_Int->pop();
	std::cout << "the value of expression is:" << val << std::endl;
	system("pause");
	return 0;
}


#endif