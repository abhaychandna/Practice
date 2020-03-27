#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	long long int sum = 0;

	while (t--)
	{
		int v[4][4] = { (0,0) };
		//bool b[4][4] = { (true,true) };
		
		long long int tsum = -INT_MAX;
		int n;
		cin >> n;

		//long long int temp = -10000000000;
		if (n != 0)
		{
			for (int i = 0; i < n; i++)
			{
				char x;
				int y;
				cin >> x >> y;
				v[x - 65][(y / 3) - 1]++;
			}

			for (int a = 0; a < 4; a++)
			{
				for (int b = (a + 1) % 4; b != a; b = (b + 1) % 4)
				{
					for (int c = (b + 1) % 4; c != b; c = (c + 1) % 4)
					{
						if (c != a)
							for (int d = (c + 1) % 4; d != c; d = (d + 1) % 4)
							{
								if (d != a && d != b)
								{

									long long int x = 0;

									vector<long long int> p;
									p.push_back(v[0][a]);
									p.push_back(v[1][b]);
									p.push_back(v[2][c]);
									p.push_back(v[3][d]);
									sort(p.rbegin(), p.rend());

									if (p[0] != 0)
										x += p[0] * 100;
									else
										x -= 100;

									if (p[1] != 0)
										x += p[1] * 75;
									else
										x -= 100;

									if (p[2] != 0)
										x += p[2] * 50;
									else
										x -= 100;

									if (p[3] != 0)
										x += p[3] * 25;
									else
										x -= 100;

									if (tsum < x)
										tsum = x;

									//cout << a << " " << b << " " << c << " " << d << " " << ++count << "\n";
								}
							}
					}
				}
			}
		}
		else
			tsum = -400;
		cout << tsum << endl;
		sum += tsum;
	}
	cout << sum << endl;
}