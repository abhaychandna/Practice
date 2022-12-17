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

map<int, int> mp;

void chkCol(vvi v) {
	fo(i, 3)
		if (v[0][i] == v[1][i] && v[1][i] == v[2][i])
			mp[v[0][i]]++;
}

void chkRow(vvi v) {
	fo(i, 3)
		if (v[i][0] == v[i][1] && v[i][1] == v[i][2])
			mp[v[i][0]]++;
}

void chkDiag(vvi v) {
	
	if (v[0][0] == v[1][1] && v[2][2] == v[1][1])mp[v[0][0]]++;
	if (v[0][2] == v[1][1] && v[2][0] == v[1][1])mp[v[0][2]]++;	
}

ll solve()
{
	mp[1] = 0, mp[0] = 0,mp[-1]=0;
	ll ans = 0;
	vector<string> s(3);
	fo(i, 3)cin >> s[i];
	vvi v(3,vi (3));
	int x = 0, o = 0, d = 0,n=3;
	fo(i, 3)
		fo(j, 3)
			if (s[i][j] == 'X')x++,v[i][j]=1;
			else if (s[i][j] == 'O')o++,v[i][j]=0;
			else d++,v[i][j]=-1;

	if (o > x || x - o > 1)return 3;

	chkCol(v);
	chkRow(v);
	chkDiag(v);

	if (mp[0] > 0 && mp[1] > 0)return 3;
	if (mp[1] > 0)
		if (x == o + 1)return 1;
		else return 3;
	if (mp[0] > 0)
		if (o == x) return 1;
		else return 3;
	if (d > 0)return 2;
	else return 1;

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