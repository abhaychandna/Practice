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

#define vi vector<int>
#define vl vector<long long int>
#define vvi vector<vector<int>> 
#define vvl vector<vector<long long int>>
#define pi pair<int,int>
#define pl pair<long long int, long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define fon(i,start,end) for(int i=start;i<end;i++)
#define fos(i,start,end,step) for(int i=start;i<end;i+=step)

using namespace std;

ll solve()
{
	ll ans = 0;
	ll n, m;
	cin >> n >> m;
	ll mn = min(m, n);
	if (m < n) {
		ll diff = n - m;
		ans += (diff * (diff + 1)) / 2;
		ans %= mod;

		diff = (m - 1) * (n-m);
		diff %= mod;
		ans += diff;
		ans %= mod;
	}

	//ifmn==1?
	ans += (mn - 1) % mod;
	for (ll i = 2; i < n; i++) {
		ans += ((mn / i)-1) % mod;
	}
	ll s = sqrt(m);
	for (ll i = 2; i <= s; i++) { // eqal?
		if (m % i != 0)continue;
		ll a = i,b = m/i;
		if (a != b && b%a !=0 && a<n && b<=n)ans++;
		b--;
		if (b < a)swap(b, a); // could give duplicates
		if (b!=a && b % a != 0)ans++;
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
		ll ans = 0;
		ans = solve();
		cout << ans << '\n';
	}
}