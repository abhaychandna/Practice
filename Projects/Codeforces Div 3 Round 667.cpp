#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>

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

	int n,m,k;
	cin >> n>>m>>k;
	vector<vector<int>> v(n);
	fo(i, n)
	{
		int cnt = m / 2;
			vector<vector<int>> rem(k);
		fo(j, m)
		{
			int x;
			cin >> x;
			rem[x % k].pb(x);
			v[i].pb(x);
		}
		sort(v[i].rbegin(), v[i].rend());
		fo(j, 70)
			sort(v[j].rbegin(), v[j].rend());

		
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--)
	{
		ll ans;
		ans = solve();
		//cout << ans << '\n';
	}
}