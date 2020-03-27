#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	// change cin cout to scanf printf
	const int MAX = 1e5 + 10;
	int ar[MAX];
	ar[0] = 0;
	ar[1] = 1;
	ar[2] = 1;
	for (int i = 2; i < MAX; i++)
	{
		int k = 0;
		int c = 0;
		for (int j = 0; j < 22 && k <= i; j++)
		{
			k = 1 << j;
			if (i & k)
				c++;
		}
		if (c & 1)
			ar[i] = 0;
		else
			ar[i] = 1;
	}

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int z, q;
		cin >> z >> q;

		vector<int> v;
		int c = 0;

		int even = 0, odd = 0;
		for (int i = 0; i < z; i++)
		{
			int r;
			cin >> r;
			v.push_back(r);
			if (v[i] >= MAX)
			{
				c = 0;
				int k = 0;
				//cin >> v[i];
				for (int j = 0; j < 32 && k <= v[i]; j++)
				{
					k = 1 << j;
					if (v[i] & k)
						c++;
				}
			}
			else
			{
				c = ar[v[i]];
			}
			if (c & 1)
				even++;
			else
				odd++;

		}

		for (int i = 0; i < q; i++)
		{
			c = 0;
			int x;
			cin >> x;
			c = ar[x];
			if (c & 1)
				cout << even << " " << odd << endl;
			else
				cout << odd << " " << even << endl;
		}
	}

}
