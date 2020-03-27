#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main()
{
	int p;
	scanf("%d", &p);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		unordered_map<int,int> m;
		int r = 1;
		vector<int> v(n);
		for (int i = 0;i < n; i++)
		{
			int x;
			cin >> x;
			v[i] = x;
			if (m[x] == 0)
			{
				m[x] = r;
				r++;
			}	
			//m[x] = m[x]++;
		}
		if (r == 2)
		{
			cout << 1;
			for (int i = 0; i < n; i++)
				cout << "1 ";
			cout << endl;
		}
		else if (r == 3)
		{
			cout << r - 1 << endl;
			for (int i = 0; i < n; i++)
			{
				cout << m[v[i]] << " ";
			}
			cout << endl;
		}
		else
		{
			int ans = 2;
			int start = v[0];
			int y = 1;
			int total = 1;
			m[v[0]] = y;
			int i = 1;
			while (v[i] == start)
				i++;
			for (; i < n; i++) // till n-1 mayber
			{
				while (v[i] == v[i + 1])
					i++;
				
				if (start == v[i + 1])
				{
					//if (vis[v[i]] == false)
					{
						m[v[i]] = y + 1;
						y++;
					}

				}
				else
				{
					i++;
					while(v[i] == v[i+1])
				}
			}
		}
		cout << r - 1 << endl;
		for (int i = 0; i < n; i++)
		{
			cout << m[v[i]] << " ";
		}
		cout << endl;
		//cout << *m.count() << endl;;
	}
}