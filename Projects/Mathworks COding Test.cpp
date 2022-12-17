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

long long int solve(vector<vector<char>> v) {

	ll n = v.size(), m = v[0].size();
	ll t = 4*n * m;
	int i = 0, j = 0;
	vvl vis(n, vl(m));
	vector<pl> steps = { {0,1},{1,0}, {0,-1}, {-1,0} };
	int id = 0;
	
	while(t--){
		i += steps[id].first, j += steps[id].second;
		if (i >= n || i < 0 || j >= m || j < 0 || v[i][j] == 'X') {
			i -= steps[id].first, j -= steps[id].second;
			id = (id + 1) % 4;
		}
		else {
			vis[i][j] = 1;
		}
	}

	ll ans = 1;
	fo(i, n)fo(j, m)ans += vis[i][j];
	return ans;
}

ll Ynot()
{
	ll ans = 0;

	

	return ans;
}

int main()
{
	ll n, m;
	cin >> n >> m;
	vector<vector<char>> v(n,vector<char>(m));
	fo(i, n)fo(j, m)cin >> v[i][j];
	cout << solve(v);
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