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
	ll ans = 0;
	ll n, k;
	cin >> n >> k;
	vl v(k);
	fo(i, k)cin >> v[i];
	ll j = 1;
	vl a;
	a.pb(0);
	fo(i, n)a.pb(i + 1);
	fo(i, k) {
		ll x = v[i];
		swap(a[j], a[x]);
		j = x + 1;
	}
	for (int i = 1; i <= n; i++)cout << a[i] << " ";
	cout << '\n';
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
		ll ans = 0;
		ans = Ynot();
		//cout << ans << '\n';
	}
}