#define SQRT_NEWTON_METHOD
#ifdef SQRT_NEWTON_METHOD
#include <iostream>

#define E 1e-6

int cnt = 0;

double sqrt_by_newton_method(double val)
{
	
	if (val == 0)
	{
		return 0;
	}
	
	double x0 = val;
	double root = 0;
	while (1)
	{
		cnt += 1;
		root = val / (2.0 * x0) + x0 / 2.0;
		if (abs(root * root - val) < E)
		{
			return root;
		}
		else
		{
			x0 = root;
		}
	}
}


int main(int argc, char** argv)
{
	double val = 0.01;
	double sqrt_val = sqrt_by_newton_method(val);
	printf("the square root %lf is: %lf\n", val, sqrt_val);
	printf("cnt = %d\n", cnt);
	printf("sqrt(%lf): %lf\n", val, sqrt(val));
	return 0;

}
#endif