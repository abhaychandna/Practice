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

bool isVowel(char c)
{
	if (c == 'A')
		return true;
	if (c == 'E')
		return true;
	if (c == 'I')
		return true;
	if (c == 'O')
		return true;
	if (c == 'U')
		return true;
	else
		return false;
}

ll solve(string s) {

	int n = s.size();
	vl cnt(26);
	fo(i, n)cnt[s[i] - 'A']++;
	ll ans = 1e9;
	fo(i, 26) {
		char c = 'A' + i;
		ll x = 0;
		
		fo(j, 26) {
			if (i == j)continue;
			int k = 1;
			if (isVowel(c) == isVowel('A' + j))k++;
			x += k * cnt[j];
		}
		ans = min(ans, x);
	}
	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("A1op.txt", "w", stdout);
	int t;
	cin >> t;
	int count = 1;
	while (t--) {
		string s;
		cin >> s;
		int n = s.length();
		ll ans = solve(s);
		cout << "Case #: " << ans << endl;
	}
	return 0;
}