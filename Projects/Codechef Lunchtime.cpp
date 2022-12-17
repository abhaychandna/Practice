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

vl solve(int k, int n, vl a, vl b) {
	vl ans;
	fo(i, n) {
		if (b[i] == k) {
			k = i;
			break;
		}
	}

	fo(i, n) {
		ll id = ((k + i) % n);
		ll x = (a[i] + b[id]) % n;
		ans.pb(x);
		//cout << x << " ";
	}
	return ans;
}

ll Ynot()
{
	ll ans = 0;

	ll n,k,s;
	cin >> n >> k >> s;
	map<ll, ll> mp;
	vl a(n), b(n);
	fo(i, n)cin >> a[i];
	a.insert(a.begin(), 0);
	vl pre(n + 1);
	pre[0] = 0;
	for (int i = 1; i <= n;i++)pre[i] = a[i] + pre[i - 1];

	for (int i = 1; i <= n; i++) {
		ll prev = pre[i - 1];
		ll sum = prev + (s*(k - 1));
		ll id = upper_bound(pre.begin(), pre.end(), sum) - (pre.begin());
		id--;
		
		ll sum2 = prev + (s * (k - 2));
		ll p = upper_bound(pre.begin(), pre.end(), sum) - (pre.begin());

		ll start = upper_bound(pre.begin(), pre.end(), pre[id] - s) - pre.begin();
		ll end = upper_bound(pre.begin(), pre.end(), pre[start] + sum) - pre.begin();
		end--;
		ll temp = end - i + 1;
		ans = max(ans, temp);
	}


	//cout << '\n';
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