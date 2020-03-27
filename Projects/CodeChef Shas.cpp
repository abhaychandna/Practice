#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long int ans[5] = { 1,1,1,1,1 };
		int s;
		cin >> s;
		//ans[0] = 1;
		//ans[3] = 1;

		for (int i = 6; i <= s; i++)
		{
			switch (i % 3)
			{

			case 0: ans[4]++; break;
			case 1: ans[2]++; break;
			case 2: ans[1]++; break;
			default:
				break;
			}
		}

		long long int a, b, c;

		a = (ans[0] * ans[0] * ans[1] * ans[1]) + (2 * ans[0] * ans[2] * ans[1] * ans[1]);
		b = (ans[1] * ans[1] * ans[2] * ans[2]) + (2 * ans[1] * ans[3] * ans[2] * ans[2]);
		c = (ans[2] * ans[2] * ans[3] * ans[3]) + (2 * ans[0] * ans[1] * ans[2] * ans[3]);

		long long int p;

		p = (ans[4] * ans[4]) * (a + b + c);

		cout << p << endl;
	}

	return 0;
}