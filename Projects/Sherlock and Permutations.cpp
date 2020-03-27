#include<iostream>
#include<cmath>
int main()
{
	int n[200], m[200], f = pow(10, 9) + 7;
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		std::cin >> m[i];
		std::cin >> n[i];
	}
	long int factn1 = 1, factm = 1, p = 1;

	for (int j = 0; j < t; j++)
	{
		factn1 = 1; factm = 1; p = 1;
		if (n[j] > 1)
		{
			for (int i = 1; i <= n[j] - 1; i++)            
			{
				factn1 = factn1 * i;
				factn1 %= f;
			}
			for (int i = 1; i <= m[j]; i++)
			{
				factm = factm * i;
				factm %= f;
			}
			for (int i = 1; i <= (n[j] - 1 + m[j]); i++)               
			{
				p = p * i;
				p %= f;
			}
			p = p / factn1;
			p = p / factm;
			p = p % f;

			std::cout << p;
		}
		else
			std::cout << "1";

		if (j < t - 1)
			std::cout << std::endl;
	}
}