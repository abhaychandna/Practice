#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<cmath>
#include<unordered_map>

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
ll r, c;
/*
ll check(deque<vl> q, vvl vis) {
	vl dx = { 1,0,-1,0 };
	vl dy = { 0,1,0,-1 };
	ll ans = 0;
	while (!q.empty())
	{
		auto v = q.front();
		q.pop_front();
		ll i = v[0], j = v[1], d = v[2];
		ans = max(ans, d);
		for (int k = 0; k < dx.size(); k++) {
			ll nx = i + dx[k], ny = j + dy[k];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c)
				if (!vis[nx][ny]) {
					vis[nx][ny] = 1;
					q.push_back({ nx,ny,d + 1 });
				}
		}

	}
	return ans;
}
*/

unordered_map<char, bool> mp;
vector<char> vvv = { 'a','e','i','o','u' };

int two_vowel(string &s) {
	int n = s.size();
	int cnt = 0;
	for (int i = 0; i < n; i++)if (mp[s[i]])cnt++;
	return cnt;
}
string Ynot()
{
	ll ans = 0;
	string s;
	cin >> s;
	int n = s.size();
	int i = 0, j = 1;
	while (i < n) {
		while (i < n && !mp[s[i]])i++;
		j = i + 1;
		while (j < n && !mp[s[j]])j++;
		if (j < n) {
			string start = s.substr(i, j - i + 1);
			int k = j + 1;
			for (int k = j + 1; k < n; k++) if (mp[s[k]])break;
			k++;
			if (k >= n)break; // or continue
			string last = s.substr(k, n - k);
			auto it = last.find(start);
			if (it == string::npos)break;

			return "Spell!";


		}

		i = j;
	}

	return "Nothing.";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for (auto c : vvv)mp[c] = 1;

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		string ans = Ynot();
		cout << "Case #" << i << ": " << ans << endl;
	}
}