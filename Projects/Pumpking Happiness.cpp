#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int q;
	cin >> q;
	while (q--)
	{
		long long int sum = 0;
		int n, k = 1, u, d;
		cin >> n;
		int v[10000];
		int f = n;
		int s;

		if (n % 2 == 0 && n != 2)
		{
			s = n / 2;
			v[s] = f;
			f--;
			u = s + 1;
			d = s - 1;

			while (f >= k)
			{
				if (d > -1)
				{
					v[d] = k;
					k++; d--;
				}
				if (u < n)
				{
					v[u] = k;
					k++; u++;
				}

				if (d > -1)
				{
					v[d] = f;
					f--; d--;
				}
				if (u < n)
				{
					v[u] = f;
					f--; u++;
				}
			}

			for (int i = 0; i < n - 1; i++)
			{
				sum += abs(v[i] - v[i + 1]);
			}

		}
		else if (n % 2 != 0 && n!=1)
		{
			s = (n - 1) / 2;
			v[s] = f;
			f--;
			u = s + 1;
			d = s - 1;

			while (f >= k)
			{
				if (d > -1)
				{
					v[d] = k;
					k++; d--;
					v[u] = k;
					k++; u++;
				}

				if (d > -1)
				{
					v[d] = f;
					f--; d--;
					v[u] = f;
					f--; u++;
				}
			}

			for (int i = 0; i < n - 1; i++)
			{
				sum += abs(v[i] - v[i + 1]);
			}
		}

		else
			sum = 1;
		
		cout << sum << endl;
	}
	return 0;
}
