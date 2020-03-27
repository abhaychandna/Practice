#include<iostream>
int main()
{
	int t;
	std::cin >> t;
	int cats = 0 , dogs = 0, legs = 0;;
	for (int i = 0; i < t; i++)
	{
		std::cin >> cats;
		std::cin >> dogs;
		std::cin >> legs;

		int possible = 0,l=0;
		for (int i = 0; i <= cats; i++)
		{
			if (i > 2 * dogs)
				break;

			l = 4 * (dogs + (cats - i));

			if (legs == l)
			{
				possible = 1;
				break;
			}
		}

		if (possible == 1)
			std::cout << "Y";
		else
			std::cout << "N";
	}
}