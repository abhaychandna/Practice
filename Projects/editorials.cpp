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

ll splits()
{
	ll ans = 0;

	ll n;
	cin >> n;
	vector<ll> v(n); 
	fo(i, n)cin >> v[i];
	
	ans += v[0];
	for (int i = 1; i < n; i++)
		ans += abs(v[i]);

	return ans;
}

ll cricket()
{
	ll n;
	cin >> n;
	
	vector<ll> runs = { 1,2,3,4,6 };
	vector<ll> dp(n+6);
	
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		for (auto run : runs) {
			if (i - run >= 0)dp[i] += dp[i - run]; 
		}
	}
	
	return dp[n];
}

bool grid() {
	ll a[2], b[2], c[2];
	cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];
	ll distA = (abs(a[0] - c[0]) + abs(a[1] - c[1]));
	ll distB = max(abs(b[0] - c[0]), abs(b[1] - c[1]));
	return distA < distB;
}

void init(int fno) {
	string ou = "cakewalk/out0" + to_string(fno) + ".txt";
	string in = "cakewalk/in0" + to_string(fno) + ".txt";
	freopen(&in[0], "r", stdin);
	freopen(&ou[0], "w", stdout);
}
void inout() {
	fclose(stdout);
	fclose(stdin);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int testFiles = 3;
	for (int fno = 0; fno < testFiles; fno++)
	{
		
		init(fno);
		//cout << cakewalk();
		int t = 1;
		cin >> t;
		while (t--)
		{
			ll ans = 0;
			ans = cakewalk();
			cout << ans << endl;
		}

		inout();
	}
}