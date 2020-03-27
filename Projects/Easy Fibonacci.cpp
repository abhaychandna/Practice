#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int t;
	cin >> t;

	int fib[200] = { 0 };
	fib[1] = 0;
	fib[2] = 1;

	for (int i = 3; i <= 200; i++)
	{
		fib[i] = ((fib[i - 1] % 10) + (fib[i - 2] % 10)) % 10;
	}

	long long int power[70];
	pow[1] = 2;
	for (int i = 2; i < 64; i++)
	{
		//power[i] = (long long int) pow(2, i);
		power[i] = 2 * power[i - 1];

	}

	while (t--)
	{
		long long int n;
		cin >> n;
		if (n > 1)
		{
			bool x = false;
			if (n >= 60)
				x = true;

			int k = 0;

			for (k = 1; k < 63; k++)
			{
				if (power[k] > n)
					break;
			}

			k--;
			n = power[k] % 60;


			int c;
			c = fib[n] % 10;

			cout << c << endl;


		}
		else
			cout << "0" << endl;
	}

}