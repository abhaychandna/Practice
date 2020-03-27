#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<algorithm>
#include<string>
using namespace std;
//remove cout neg
void bit(long long int a,vector<int> &v,int &c)
{
	for (int i = 63; i >= 0; i--)
	{

		int k = a >> i;

		if (k & 1)
		{
			v[i] = 1;
			if (!c)
				c = i;
		}
		else
		{
			v[i] = 0;
		}
	}
}

int main()
{
	int p = 1000000007;
	int t;
	cin >> t;
	while (t--)
	{
		long long int a,b;
		cin >> a >> b;
		int neg = 0;
		vector<int> v(70);
		int count = 0;
		bit(a, v, count);

		long long int n = 0;
		long long int sum = 0;
		for (long long int i = 0; i <= count; i++)
		{
			if (v[i])
			{
				long long int r;
				long long int x = 1;
				x = x << i;
				r = x - n - 1;


				if (b - a < r)
					r = b - a;

				sum += ((x%p) * (r%p)%p);
				if (sum < 0)
					neg = 1;
				//sum %= p;
				//if (sum < 0)
					//neg = 1;

				n += x;
			}
		}
		sum += a;
		if (sum < 0)
			neg = 1;
		sum %= p;
		//if (sum < 0)
			//neg = 1;
		cout << sum << " " << neg << endl;

	}
}