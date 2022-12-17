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

bool solve(string s) {
	int i = 2;
	while (i < s.size())
		if (s[i] == s[i - 1] && s[i - 1] == s[i - 2])return false;
		else i++;
	return true;
}

ll Ynot()
{
	ll ans = 0;
	ll n;
	cin >> n;

	//string s = "";

	for (int i = pow(10,n-1); i < pow(10, n); i++) {
		string s = to_string(i);
		auto x = s.find('0');
		if (s.find('0') == string::npos) {
			if (solve(s))ans++;
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