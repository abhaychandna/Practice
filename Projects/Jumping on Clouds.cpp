#include<iostream>

void main()
{
	int n, a[100] = { 0 };

	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];
	}
	int moves = 0;
	for (int i = 0; i < n-1;)
	{
		if (a[i + 2] == 0 && i+2<n)
			i = i + 2;
		else
			i++;
		moves++;
	}

	std::cout << moves;
}