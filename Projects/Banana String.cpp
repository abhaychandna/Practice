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
		int n, p;
		cin >> n >> p;
		string s;
		cin >> s;

		vector<int> a(n);
		vector<int> b(n);

		if (s[0] == 'b')
			b[0] = 1;
		else
			b[0] = 0;
		for (int i = 1; i < n; i++)
		{
			
			if (s[i] == 'b')
				b[i] = b[i - 1] + 1;
			else
				b[i] = b[i - 1];
		}

		for (int i = n - 2; i >= 0; i--)
		{
			if (s[i + 1] == 'a')
				a[i] = a[i + 1] + 1;
			else
				a[i] = a[i + 1];
		}
		
		auto it = lower_bound(b.begin(), b.end(), 1);
		int x = *it + 1;
		int ans = -1,max = -1;
		for (int i = n-1; i >= 0; i--) // wrong to start with n-2
		{
			int ca, cb;
			ca = a[i], cb = b[i];
			int x = p/2-cb;
			if (x == 0)
			{
				ans = i;
				if (max < ans)
					max = ans;
			}
			else if (x > 0)
			{
				x -= ca;
				if (x >= 0)
				{
					ans = i;
					if (max < ans)
						max = ans;
				}
			}
		}
		if (ans == -1)
		{
			cout << s << endl;
		}
		else
		{
			for (int i = 0; i <= ans-1; i++)
				cout << "a";
			for (int i = ans; i < n; i++)//not working for swaps
				cout << s[i];
			cout << endl;
		}
	}
}