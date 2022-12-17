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

long long inv(long long a, long long b) {
	return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

ll fact(ll n)
{
	ll f = 1;
	for (ll i = 2; i <= n; i++)
		f = (f * i) % mod;
	return f;
}

ll Ynot()
{
	ll ans = 0;
	ll n;
	cin >> n;

	ll k = 1;
	ll p = n / 2;
	ll l = n / 2;
	if (n % 2)l++;

	vl f(n + 3);
	f[0] = 1;
	for (ll i = 1; i < f.size(); i++) {
		f[i] = (i * f[i - 1]) % mod;
	}

	ans = 0;
	k = p;
	for (ll i = 1; i < n && l>0; i++) {
		ll r = f[n - (i + 1)];
		k = (k * (l)) % mod;
		l--;

		r = (r * k) % mod;
		r = (r * i) % mod;
		ans = (ans + r) % mod;
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
		ans = Ynot();
		cout << ans << '\n';
	}
}