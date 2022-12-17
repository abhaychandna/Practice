#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<fstream>

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


	return ans;
}

int main()
{
	freopen("A1.txt", "r", stdin);
	freopen("A1op.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		ll z = 0;
		//string s;
		//cin >> s;
		char x = '0' + i;
		string ans = "Case #";
		//+x + ': ';
		ans += to_string(i);
		ans += ": ";
		//
		//cout << ans;
		z = solve();
		cout << ans << z << '\n';
		//cout << ans<<z << '\n';
	}
}