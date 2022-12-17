#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>

#define ll long long 
#define mod 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

#define vi vector<int>
#define vl vector<long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define fos(i,n,s,l) for(int i=s;i<n;i+=l)

using namespace std;
string k = "";
ll solve()
{
		return 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{

		string s;
		cin >> s;
		char x = '0' + i;
		string ans = "Case #";
		//+x + ': ';
		ans += to_string(i);
		ans += ": ";
		bool b = false;
		int c = 0, idx = -1;
		fo(j, s.length())
		{
			if (s[j] == 'A')
			{
				idx = j;
				b = true;
			}if (b)
			{
				if (s[j] == 'B')
					c++;
			}
		}
		idx++;
		int p = s.length() - idx;
		int r = p / 2;
		r += p % 2 ? 1 : 0;
		if (p == 0 || (c<p && c>=r))
			ans += "Y";
		else
			ans += "N";
		cout << ans << '\n';
	}
}