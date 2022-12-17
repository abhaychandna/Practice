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

#define fo(i,n) for(long long int i=0;i<n;i++)
#define fos(i,start,end,step) for(long long int i=start;i<end;i+=step)

using namespace std;

ll solve()
{
	ll ans = 0;
	ll n, k;
	cin >> n >> k;
	ll total = 0;
	vector<int> v(n);
	fo(i, n) {
		cin >> v[i];
		total += v[i];
	}

	ll i = 0,cnt=0;
	if (k == 1)return total;
	if (k == n) return ((total * (total+1))/2);

	ll mn = 0, j = 0;
	while (i < k) {
		cnt += v[i++];
	}
	mn = cnt;
	while (i < n) {
		cnt -= v[j++];
		cnt += v[i++];
		mn = min(mn, cnt);
	}

	ans = (mn * (mn + 1)) / 2;
	total -= mn;
	ans += total;

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
		cout << ans << '\n';
	}
}