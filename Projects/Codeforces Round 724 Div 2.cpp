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

vector<string> vs;
int sz = 10007;

ll gcd(ll a, ll b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

ll Ynot()
{
	vl ans;
	ll n;
	cin >> n;
	string s;
	cin >> s;
	map<pair<ll, ll>, ll> mp;
	map<char, int> dict;
	dict['D'] = 0, dict['K'] = 1;
	vl cnt(2);
	cnt[dict[s[0]]]++;

	ll i = 1;
	ans.pb(1);
	
	while (i < n && s[i] == s[i - 1]) {
		ans.pb(ans[ans.size() - 1] + 1);
		cnt[dict[s[i]]]++;
		i++;
	}

	while (i < n) {
		cnt[dict[s[i]]]++;
		pair<ll, ll> x;// = { cnt[0],cnt[1] };
		ll g = gcd(cnt[0], cnt[1]);
		ll a = cnt[0] / g, b = cnt[1] / g;
		x = { a,b };
		mp[x]++;
		ans.pb(mp[x]);
		i++;
	}

	fo(i, n)cout << ans[i] << " ";
	cout << '\n';

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