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
	ll n;
	cin >> n;
	//vi v(n);
	string s;
		cin >> s;
		int cnt = 0;
	fo(i, n) {
		if (s[i] == '*')
			cnt++;
	}
	int gcnt = cnt;

	if (cnt == 1) {
		return 0;
	}
	else if (cnt == 2) {
		int mn = 1e12,mx = -1;
		fo(i, n) {
			if (s[i] == '*') {
				mn = min(mn, i);
				mx = max(mx, i);
			}
		}
		return (mx - mn - 1);
	}
	
	vi hcnt;
	int k = cnt / 2;
	cnt = 0;
	fo(i, n) {
		if (s[i] == '*')
			cnt++;
		if (cnt == k) {
			hcnt.pb(i);
			k = -1;
		}
	}
	cnt = gcnt;
	if (cnt % 2 == 1) {
		k = cnt / 2;
		k++;
		cnt = 0;
		fo(i, n) {
			if (s[i] == '*')
				cnt++;
			if (cnt == k) {
				hcnt.pb(i);
				k = -1;
			}
		}
		cnt = gcnt;
		//hcnt.pb((cnt / 2) + 1);
	}
	
	fo(h, hcnt.size()) {
		ans = 1e18;
		int id = hcnt[h];
		int i = id - 1;
		ll dest = i;
		ll lans = 0;
		while (i >= 0) {
			if (s[i] == '*') {
				lans += dest - i;
				i--;
				dest--;
			}
			else {
				i--;
			}
		}
		i = id + 1;
		dest = i;
		while (i < n) {
			if (s[i] == '*') {
				lans += i - dest;
				i++;
				dest++;
			}
			else {
				i++;
			}
		}
		ans = min(ans, lans);
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