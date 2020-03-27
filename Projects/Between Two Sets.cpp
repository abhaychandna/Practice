#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int gcd(int, int);

int lcm(int x, int y)
{
	return x * (y / gcd(x, y));
}

int gcd(int x, int y)
{
	if (x == 0)
		return y;
	else
		return gcd(y % x, x);
}
int main()
{
	int m, n;
	cin >> n >> m;
	vector<int> a, b;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);

	}

	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		b.push_back(x);

	}
	int l = a[0], g = b[0];
	for (int i = 1; i < n; i++)
	{
		l = lcm(l, a[i]);
	}

	for (int i = 0; i < m; i++)
	{
		g = gcd(g, b[i]);
	}

	//if (g % l == 0)
	/*int ans= (g / l);

	if (g == b[0])
		ans--;

	cout << ans;
	*/
	int count = 0;
	for (int i = l; i <= b[0]; i+=l)
	{
		if (g % l == 0)
			count++;
	}
	cout << count;
}