#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long int n, v;
		cin >> n >> v;
		vector<int> p;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			p.push_back(x);
		}

		sort(p.begin(), p.end());

		//long long int t = v;
		long long int ans = 0;

		vector<int> dif;
		//dif.push_back(0);
		for (int i = 1; i < n; i++)
		{
			int x = p[i] - p[i - 1];
			dif.push_back(x);
		}
		//long long int temp = 0;
		long long int prev = 0;
		long long int rem = 0;
		long long int i = 1;
		for (i = 1; i < n; i++)
		{
			//temp = prev;
			prev += dif[i - 1] * i;
			if (prev < v)
			{
				continue;
			}
			else
			{
				long long int extra = prev - (dif[i - 1] * i);
				extra = v - extra;
				extra /= i;
				ans = p[i - 1] + extra;
				break;


			}
		}

		if (ans == 0)
		{
			ans = p[0] + (v / n);
		}

		if (i == n) // less than or equal to?
		{
			long long int extra = v - prev;
			//extra = v - extra;
			extra /= i;
			ans = p[i - 1] + extra;
		}

		cout << ans << endl;
	}
}