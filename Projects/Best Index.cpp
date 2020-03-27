#include<iostream>
int main()
{
	int a[10000], t, max = 0, k = 1, sum = 0, osum = 0;;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		std::cin >> a[i];
	}

	for (int i = 0; i < t; i++)
	{
		k = 1;
		for (int j = i;j<t;)
		{
			if (j + k < t + 1)
			{
				for (int n = 0; n < k; n++)
				{
					sum = sum + a[j];						// errr here as j goes out of scope
					j++;
					
				}
				k++;
			}
			else
				j++;
		}
		if (i == 0)
			osum = sum;
		if (osum < sum)
			osum = sum;
		sum = 0;
		std::cout << osum << "\n";

	}

}
