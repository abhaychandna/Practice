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
#define vvi vector<vector<int>> 
#define vvl vector<vector<long long int>>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define fos(i,start,end,step) for(int i=start;i<end;i+=step)

using namespace std;
ll n, x, y, k;
ll mx, mn;

vl right(ll x, ll y) {
	vl v(2);

	v[0] = y;
	v[1] = mx;

	return v;
}
vl bottom(ll x, ll y) {
	vl v(2);

	v[0] = mx;
	v[1] = (n-1)-x;

	return v;
}
vl left(ll x, ll y) {
	vl v(2);

	v[0] = y;
	v[1] = mn;

	return v;
}
vl top(ll x, ll y) {
	vl v(2);

	v[0] = mn;
	v[1] = (n-1)-x;

	return v;
}

ll solve()
{
	ll ans = 0;
	cin >> n >> x >> y >> k;

	k %= 4;
	if (k == 0)k = 4;

	if (n % 2 == 1) {
		if (x == n / 2 && y == n / 2)
		{
			cout << n / 2 << " " << n / 2<<'\n';
			return 1;
		}
	}

	mx = n - 1, mn = 0;
	//calc();
	if (mx < mn)swap(mx, mn);

	if (x <= n / 2) {
		if (y <= n / 2) {

			if (k > 0) {
				vl v(2);
				v = right(x, y);
				x = v[0];
				y = v[1];
				k--;
			}
			if (k > 0) {
				vl v(2);
				v = bottom(x, y);
				x = v[0];
				y = v[1];
				k--;
			}
			if (k > 0) {
				vl v(2);
				v = left(x, y);
				x = v[0];
				y = v[1];
				k--;
			}
			if (k > 0) {
				vl v(2);
				v = top(x, y);
				x = v[0];
				y = v[1];
				k--;
			}
			cout << x << " " << y << '\n';
			return 1;
		}
		
		
		if (k > 0) {
			vl v(2);
			v = bottom(x, y);
			x = v[0];
			y = v[1];
			k--;
		}
		if (k > 0) {
			vl v(2);
			v = left(x, y);
			x = v[0];
			y = v[1];
			k--;
		}
		if (k > 0) {
			vl v(2);
			v = top(x, y);
			x = v[0];
			y = v[1];
			k--;
		}
		if (k > 0) {
			vl v(2);
			v = right(x, y);
			x = v[0];
			y = v[1];
			k--;
		}
		cout << x << " " << y << '\n';
		return 1;
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
		//cout << ans << '\n';
	}
}