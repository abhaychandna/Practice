#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<fstream>

#define ll long long 
#define mod 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

#define vi vector<int>
#define vl vector<long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define fos(i,start,end,step) for(int i=start;i<end;i+=step)

using namespace std;

ll solve()
{
	ll ans = 0;
	int n;
	cin >> n;
	cout << "n="<<n << '\n';
	ll prev = 0;
	for (int i = 1; i <= n; i++)
	{
		vl v,pre;
		v.pb(0);
		pre.pb(0);
		ll total = 0;
		ll tillnow = 0;
		fos(j, 1, i + 1, 1)v.pb(j), pre.pb(pre[pre.size() - 1] + j), total += j;
		ll count = 0;
		for (int j = 1; j <= i; j++)
		{
			
			for (int k = j + 1; k <= i; k++)
			{
				
				swap(v[j], v[k]);
				total = 0, tillnow = 0;
				for (int l = 1; l <= i; l++)
				{
					total += v[l];
				}
				
				for (int l = 1; l < i; l++)
				{
					tillnow += v[l];
					if (total - tillnow == tillnow)
						count++;// cout << "j,k = " << j << "," << k << '\n';
				}


				swap(v[j], v[k]);
				/*ll temp = pre[k - 1] - j + k;
				//pre[k - 1] -= j;
				//pre[k - 1] += k;
				ll x = total - pre[k-1];
				x = x - k + j;

				if (temp == x)
				{
					cout << "j,k = " << j << "," << k << '\n';
				}*/
			}
		}
		if (count)
		{
			int diff = i - prev;
			cout << "\ni = " << i << "\ncount = "<<count<<"\ndif = "<<diff<<'\n';
			prev = i;
			//cout << count << '\n';
		}
	}
	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--)
	{
		ll ans;
		ans = solve();
		cout << ans << '\n';
	}
}