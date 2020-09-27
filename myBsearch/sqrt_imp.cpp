//#define SQRT_IMP
#ifdef SQRT_IMP
#include <iostream>

using namespace std;

int cnt = 0;

#define MAX(a, b) (a >= b ? a : b)

double sqrt_imp(double val)
{
	#define E 0.000001

	double start = 0;
	double end = 0;
	double mid = 0.0;


	/*if (val >= 1)
	{
		start = 1;
		end = val;
	}
	else
	{
		start = val;
		end = 1;
	}*/
	end = MAX(val, 1);
	
	while (1)
	{
		cnt++;
		mid = start + ((end - start) / 2);
		if (((mid * mid - val) <= E) && ((mid * mid - val) >= -E))
		{
			return mid;
		}
		else if ((mid * mid - val) > E)
		{
			end = mid;
		}
		else
		{
			start = mid;
		}
	}
}


int main(int argc, char** argv)
{
	double val = 1520254;
	double sqrt_val = sqrt_imp(val);
	printf("the sqrt of number %lf is %lf\n", val, sqrt_val);
	printf("count is %d\n", cnt);
	return 0;
}

#endif