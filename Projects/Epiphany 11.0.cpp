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
	string ans = "Ha";
	ll n, s;
	cin >> n >> s;

	vector<vl> v, b;
	fo(i, n) {
		ll x, y;
		cin >> x >> y;
		if (y > 0)v.pb({ x,y });
		else {
			y = -y;
			b.pb({ y, x,y });
		}
	}
	sort(v.begin(), v.end());
	ll cnt = 0;
	fo(i, v.size()) {
		if (s < v[i][0])break;
		s += v[i][1];
		cnt++;
	}
	sort(b.begin(), b.end());
	fo(i, b.size()) {
		auto x = b[i];
		if (s < b[i][1])continue;
		cnt++;
		s -= b[i][2];
	}
	cout << cnt << '\n';
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	//cin >> t;
	while (t--)
	{
		ll ans = 0;
		ans = Ynot();
		//cout << ans << '\n';
	}
}