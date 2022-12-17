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

#define vvl vector<vector<long long int>>
#define pl pair<long long int, long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define forev(i,n) for(int i=n-1;i>=0;i--)

using namespace std;

long long int solve(int k, int n, vector<int> &a, vector<vector<int>> &p,int x) {
	map<int, int> mp;
	long long int total, i, j, ans = 0;
	mp.clear();
	total = 0, i = 0, j = 0;
	while (j < k) {

		if (i < n && j < k) {
			if (a[i] <= p[j][x]) {
				mp.clear();
				total = 0;

				while (j < k && p[j][x] == a[i])
					j++;

				i++;
			}
			else {
				ans += total - mp[p[j][!x]];
				total++;
				mp[p[j][!x]]++;
				j++;
			}
			continue;
		}
		if (i >= n) {
			while (j < k) {
				ans += total - mp[p[j][!x]];
				total++;
				mp[p[j][!x]]++;
				j++;
			}
			break;
		}
	}
	return ans;
}

bool comp(vector<int> &x, vector<int> &y) {
	if (x[1] == y[1])
		return x[0] < y[0];
	return x[1] < y[1];
}

ll Ynot()
{
	ll ans = 0;
	ll n;
	cin >> n;
	vl v(n);
	map<ll, ll> mp;
	fo(i, n) {
		cin >> v[i];
		mp[v[i]]++;
	}
	auto it = mp.rbegin();
	it--;
	ll cnt2 = (*it).first;
	ll cnt = *max_element(v.begin(), v.end());
	//cnt = mp[cnt];
	if (mp[cnt] > 1)return fact(n);

	if (cnt - cnt2 > 1)return 0;
	
	

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