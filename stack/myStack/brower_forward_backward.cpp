//#define BROWER_FORWARD_BACKWARD
#ifndef BROWER_FORWARD_BACKWARD

#include <iostream>
#include <string>
#include "arrayStack.h"

using namespace std;

int main(int argc, char** argv)
{
	string input;
	cout << "input the number or f means forward or b means backward:" << endl;
	getline(cin, input);

	cout << input << endl;
	system("pause");
	return 0;
}



#endif