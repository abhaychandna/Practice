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

#define fo(i,n) for(int i=0;i<n;i++)
#define fos(i,start,end,step) for(int i=start;i<end;i+=step)

using namespace std;

ll solve()
{
	ll ans = 0;
	string yes = "Yes", no = "No";
	int n;
	cin >> n;
	vl v(n);
	ll mx = -2e9;
	fo(i, n) {
		cin >> v[i];
		mx = max(mx, v[i]);
	}
	if (n == 1) {
		cout << yes << '\n';
		return 1;
	}
	if (n == 2) {
		if (v[0] == v[1]) {
			cout << yes << '\n';
			return 1;
		}
		cout << no << '\n';
		return 1;
	}
	vl temp = v;
	for (int i = 0; i < n-2;i++) {
		ll diff = mx - v[i];
		if (diff < 0) {
			v = temp;
			for (int i = n - 1; i >= 2; i--) {
				ll diff = mx - v[i];
				if (diff < 0) {
					cout << no << '\n';
					return 1;
				}
				v[i] += diff;
				v[i - 1] += diff;
				v[i - 2] += diff;
			}
			if (v[0] != mx || v[1] != mx) {
				cout << no << '\n';
				return 1;
			}
			cout << yes << '\n';
			return 1;
		}
		v[i] += diff;
		v[i + 1] += diff;
		v[i + 2] += diff;
	}

	if (v[n - 1] != mx || v[n - 2] != mx) {

		v = temp;

		for (int i = n - 1; i >= 2; i--) {
			ll diff = mx - v[i];
			if (diff < 0) {
				cout << no << '\n';
				return 1;
			}
			v[i] += diff;
			v[i - 1] += diff;
			v[i - 2] += diff;
		}
		if (v[0] != mx || v[1] != mx) {
			cout << no << '\n';
			return 1;
		}
	}
	
	cout << yes << '\n';

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
		//cout << ans << '\n';
	}
}