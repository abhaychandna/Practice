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
		int n,p;
		cin >> n >> p;
		vector<int> a(n), b(n);

		for (int i = 0; i < n; i++)
			cin >> a[i];

		for (int i = 0; i < p; i++)
		{
			int x;
			cin >> x;
			b[x-1]=1;
		}

		for (int i = 0; i < n-1; i++)
		{
			if (b[i] == 1)
			{
				int j = i;
				while (b[j] == 1)
					j++;
				sort(a.begin() + i, a.begin() + j + 1);
			}
		}
		bool z = true;
		for (int i = 0; i < n-1; i++)
		{
			z = z & (a[i] <= a[i + 1]);
		}
		z ? cout << "YES" << endl : cout << "NO" << endl;
	}
}