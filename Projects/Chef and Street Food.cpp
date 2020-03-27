#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long int n, s, p, v,max = - 10000;
		cin >> n;
		while (n--)
		{
			cin >> s >> p >> v;

			long long int ans = ((p / (s + 1)) * v);

			if (ans > max)
				max = ans;
		}
		cout << max << endl;
	}
}