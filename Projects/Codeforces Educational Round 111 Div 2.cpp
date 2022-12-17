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

bool check3(ll a,ll b, ll c){
	if (a == b)return false;
	if (a > b&& c <= b)return false;
	if (a < b && c >= b)return false;
	return true;
}

bool diff(ll a, ll b, ll c) {
	if (a == b || a == c || b == c)return false;
	return true;
}


ll Ynot()
{
	ll ans = 0;
	ll n;
	cin >> n;
	vl v(n);
	fo(i, n)cin >> v[i];

	if (n == 1)return 1;
	ans += n;
	ans += (n - 1);

	for (int i = 0; i < n-2; i++) {
		if (check3(v[i], v[i + 1], v[i + 2])) {
			ans++;
		}
	}

	for (int i = 0; i < n - 3; i++) {
		if (check3(v[i], v[i + 1], v[i + 2]) && diff(v[i],v[i+1],v[i+2])) {
			ll mx = -1, mn = 1e12;
			for (int j = i; j < i + 3; j++)mx = max(mx,v[j]),mn=min(mn,v[j]);
			if ( !(v[i+2]>mn && v[i+2]<mx) && v[i + 3] < mx&& v[i + 3] > mn)ans++;
		}
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