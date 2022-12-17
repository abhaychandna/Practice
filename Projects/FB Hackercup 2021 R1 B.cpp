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

ll check(string s) {
	ll res = 0;
	for (auto c : s) {
		if (c == 'O')return 1e9;
		if (c == '.')res++;
	}
	return res;
}

string Ynot()
{
	ll ans = 1e9;
	ll n;
	cin >> n;
	vector<string> v(n);
	fo(i, n)cin >> v[i];

	ll mn = 1e9;
	fo(i, n) {
		mn = min(mn, check(v[i]));
		string x = "";
		fo(j, n)x += v[j][i];
		mn = min(mn, check(x));
	}

	if (mn == 1e9) {
		return "Impossible";
	}

	ans = 0;
	fo(i, n) {
		if (check(v[i]) == mn)ans++;
		string x = "";
		fo(j, n)x += v[j][i];
		if (check(x) == mn)ans++;
	}

	fo(i, n) {
		fo(j, n) {
			if (v[i][j] != '.')continue;
			string x = "";
			fo(k, n)x += v[k][j];

			if ((check(v[i]) == 1) && (check(x) == 1))ans--;
		}
	}

	return to_string(mn)+" "+to_string(ans);
	
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("Bop.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		string z;
		//string s;
		//cin >> s;
		char x = '0' + i;
		string ans = "Case #";
		//+x + ': ';
		ans += to_string(i);
		ans += ": ";
		//cout << ans;
		z = Ynot();
		cout << ans << z << '\n';
		//cout << ans<<z << '\n';
	}
}