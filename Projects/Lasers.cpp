#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, q;
		cin >> n >> q;
		vector<int> v;
		v.push_back(0);
		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}

		for (int i = 0; i < q; i++)
		{
			int x1, x2, y;
			cin >> x1 >> x2 >> y;
			int ans = 0;
			for (int j = x1; j < x2; j++)
			{
				if (v[j] <= y && v[j + 1] >= y)
					ans++;
				else if (v[j] >= y && v[j + 1] <= y)
					ans++;
			}
			cout << ans << endl;
		}
	}
}