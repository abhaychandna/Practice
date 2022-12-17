#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<fstream>
#include<set>

#define ll long long 
#define mod 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

#define vi vector<int>
#define vl vector<long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define fos(i,n,s,l) for(int i=s;i<n;i+=l)

using namespace std;


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("outputd1.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		ll n, m;
		cin >> n >> m;
		string ans = "";
		ans = "Case #";
		ans += to_string(i);
		ans += ":";
		cout << ans << '\n';
		string yes = "Y", no = "N";
		vl v(n);
		fo(j, n)cin >> v[j];
		bool b = false;
		int k = m;
		for (int j = 1; j < n-1; j++)
		{
			if (v[j] != 0)
				k = m;
			else
			{
				k--;
				if (k == 0)
				{
					b = true;
					break;
				}
			}
		}
		if (b)
		{
			cout << -1 << '\n';
			continue;
		}
		if (m >= (n - 1))
		{
			cout << 0 << '\n';
			continue;
		}

		multiset<long long int> pq;
		vl x;
		int j;
		for (j = n - 2; j > (n - 2 - m); j--)
		{
			if (v[j] != 0)
			{
				pq.insert(v[j]);
				
			}
			x.push_back(v[j]);
		}
		int idx = 0;
		b = false;
		ll mini = 0;
		for (; j > 0 ; j--) // check this!!
		{
			if (v[j] != 0)
			{
				 mini = *pq.begin();
				mini += v[j];
				pq.insert(mini);
				x.push_back(mini);
			}
			else
			{
				x.push_back(0);
			}
			if (idx < x.size())
			{
				if (x[idx] != 0)
				{
					auto r = pq.find(x[idx]);
					pq.erase(r);
				}
			}
			else
			{
				cout << -1 << '\n';
				b = true;
				break;
				// do sth?!
			}
			idx++;
		}
		if (!b)
		{
			mini = *pq.begin();
			cout << mini << '\n';
		}

	}
}