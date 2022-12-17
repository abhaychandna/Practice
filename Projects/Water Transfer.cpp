#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>

#define ll long long 
#define mod 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

#define vi vector<int>
#define vl vector<long long int>
#define vvi vector<vector<int>> 
#define vvl vector<vector<long long int>>
#define pb push_back

#define fo(i,n) for(long long int i=0;i<n;i++)
#define fos(i,start,end,step) for(long long int i=start;i<end;i+=step)

using namespace std;

ll solve()
{
	ll ans = 0;

	ll n, m, k;
	cin >> n >> m >> k;

	vvi cap(n, vi(m));
	vvi dir = cap;
	map<char, int> mp;
	mp['U'] = 1;
	mp['R'] = 2;
	mp['D'] = 3;
	mp['L'] = 4;
	int mx = -1;

	fo(i, n) 
		fo(j, m) {
			cin >> cap[i][j];
			mx = max(mx, cap[i][j]);
		}

	fo(i, n) {
		string s;
		cin >> s;
		fo(j, m) {
			dir[i][j] = mp[s[j]];
		}
	}

	int low = 0, high = mx;
	
	while (low <= high) {
		int mid = (low + high) / 2;

		vvi adj(n, vi(m));

		fo(i, n) {
			fo(j, m) {

				fo(k, 4) {

				}

			}
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
		ll ans;
		ans = solve();
		cout << ans << '\n';
	}
}