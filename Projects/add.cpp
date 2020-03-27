#include <iostream>
#include "header.h"
int readNumber()
{
	int x;
	std::cin >> x;
	return x;
}

void writeAnswer(int x, int y)
{
	std::cout << x + y;
}