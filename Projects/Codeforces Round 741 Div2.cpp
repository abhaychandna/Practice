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

void pf(vl v) {
	cout << v.size() << '\n';
	fo(i, v.size())cout << v[i];
	cout << '\n';
	return;
}

void Ynot()
{
	ll ans = 0;

	ll k;
	cin >> k;
	string s;
	cin >> s;
	vl cnt(10);
	fo(i, k)cnt[s[i] - '0']++;

	vl v = { 1,4,6,8,9 };
	fo(i, v.size()) {
		if (cnt[v[i]]) {
			pf({ v[i] });
			return;
		}
	}

	v = { 2,5 };
	fo(i, v.size()) {
		int x = 1e9;
		for(int j=1;j<k;j++)
			if ( (s[j] - '0') == v[i]) x = j;
		if (x != 1e9) {
			pf({ s[0]-'0',v[i] });
			return;
		}
	}

	v = { 2,3,5,7 };
	fo(i, v.size()) {
		if (cnt[v[i]] > 1) {
			pf({ v[i],v[i] });
			return;
		}
	}

	v = { 7 };
	fo(i, v.size()) {
		if (cnt[7] && cnt[2]) {
			int x = -1e9, y = 1e9;
			fo(j, k) {
				if (s[i] == '7')x = max(x, j);
				if (s[i] == '2')y = min(y, j);
			}
			if (x < y) {
				pf({ 2,7 });
				return;
			}
		}
			
	}
	return;
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
		Ynot();
		//cout << ans << '\n';
	}
}