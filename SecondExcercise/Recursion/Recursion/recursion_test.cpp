#include <iostream>


int Fibonacci(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}


unsigned int factorial(unsigned int n)
{
	if (n == 0) return 1;
	return n * factorial(n - 1);
}


int main(int argc, char** argv)
{
	return 0;
}