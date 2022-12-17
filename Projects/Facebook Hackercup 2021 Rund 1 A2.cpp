#define _CRT_SECURE_NO_WARNINGS
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

ll solve() {

	ll ans = 0;
	ll n;
	cin >> n;
	string s;
	cin >> s;

	vl id(2, n);
	vvl nxt(n, vl(2, n));

	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == 'X')id[1] = i;
		if (s[i] == 'O')id[0] = i;
		nxt[i] = id;
	}

	int x = 0, y = 0;
	if (nxt[0][1] < nxt[0][0])x = 1;

	y = nxt[0][x];
	if (y == n)return 0;

	vl k;
	//k.pb(y);
	ll total = 0;
	x = !x;
	ll firstx = x;
	y = nxt[y][x];
	while (y < n) {
		k.pb(y);
		total += (n - y);
		//ans++;
		x = !x;
		y = nxt[y][x];
	}
	reverse(k.begin(), k.end());

	ll prev = 0;
	x = firstx;
	for (int i = 0; i < n; i++) {
		if (k.empty())break;
		
		if (nxt[i][x] > nxt[i][!x]) {
			int f = -1;
		}
		else {
			x=!x;
			total -= (n - k[k.size() - 1]);
			k.pop_back();
		}
		
		ans = (ans + total)%mod;
	}
	
	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		ll ans = solve();
		cout << "Case #" << i << ": " << ans << endl;
	}
	return 0;
}