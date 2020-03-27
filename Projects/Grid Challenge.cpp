#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int n;
		cin >> n;

		vector<string> c;
		//vector<vector<int>> v(n,vector<int> (n));
		//vector<int> ans;
		//adjacent_difference(c.begin(), c.end(), ans);
		for (int i = 0; i < n; i++)
		{
			string x;
			cin >> x;
			c.push_back(x);
			sort(c[i].begin(), c[i].end());
		}
		bool s=true;
		for (int j = 0; j < n; ++j)
		{
			for (int i = 0; i < n - 1; ++i)
			{
				string s1 = c[i],s2=c[i+1];
				if (s1[j] > s2[j])
				{
					s = false;
					break;
				}

			}
			if (!s)
				break;
		}
		if (s)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
}