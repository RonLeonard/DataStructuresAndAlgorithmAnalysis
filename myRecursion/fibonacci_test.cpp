//#define FIBONACCI_TEST
#ifndef FIBONACCI_TEST
#include <iostream>


using namespace std;
/**************************************
*	1. 第一个月初有一对刚诞生的兔子
*	2. 第二个月之后（第三个月初）它们可以生育
*	3. 每月每对可生育的兔子会诞生下一对新兔子
*	4. 兔子永不死去
*
****************************************/

/*******calculate the count of rabbit based on month.*******/

int depth = 0;
int calc_countofrabbit(int n)
{
	++depth;
	if (depth > 50)
	{
		return -1;
	}
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	return calc_countofrabbit(n - 1) + calc_countofrabbit(n - 2);
}

int main(int argc, char** argv)
{
	cout << "the fibonacci is 1, 1, 2, 3, 5, 8, 13, 21...." << endl;
	
	cout << calc_countofrabbit(1) << ", " \
		<< calc_countofrabbit(2) << ", " \
		<< calc_countofrabbit(3) << ", " \
		<< calc_countofrabbit(4) << ", " \
		<< calc_countofrabbit(5) << ", " \
		<< calc_countofrabbit(6) << ", " \
		<< calc_countofrabbit(7) << ", " \
		<< calc_countofrabbit(8) << endl;
}


#endif