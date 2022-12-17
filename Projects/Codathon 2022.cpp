#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<cmath>

#define ll long long 
#define mod 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

#define vl vector<long long int>
#define vvl vector<vector<long long int>>
#define pl pair<long long int, long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define forev(i,n) for(int i=n-1;i>=0;i--)

using namespace std;
ll Ynot()
{
	ll n;
	cin >> n;
	vl v(n+1);
	for (int i = 1; i <= n; i++)cin >> v[i];
	map<int, int>mp;
	for (int i = 1; i <= n; i++) {
		mp[v[v[i]]] = v[i];
	}
	vl ans(n + 1);
	vl vis(n + 1);
	ll sum = 0;
	vl startcnt(n + 1,-1);
	for (int i = 1; i <= n; i++) {
		ll cnt = 0;
		int j = i;
		vl x;
		while (vis[j] == false) {
			startcnt[v[j]] = cnt;
			if(startcnt[j]!=-1)
				ans[j] = cnt - startcnt[j];
			else {
				ans[j] = 
			}
			cnt++;
			x.pb(j);
			vis[j] = true;
			j = mp[j];
		}
	}
	for (int i = 1; i <= n; i++)sum += ans[i];
	cout << sum << '\n';
	for (int i = 1; i <= n; i++)cout << ans[i] << " ";
	return 0;
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
		ll ans = 0;
		ans = Ynot();
		//cout << ans << '\n';
	}
}