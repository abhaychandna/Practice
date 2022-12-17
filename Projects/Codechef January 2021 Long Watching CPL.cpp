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
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define fos(i,start,end,step) for(int i=start;i<end;i+=step)

using namespace std;

ll n, k, nmax=4001;
vector<vl> dp(nmax, vl(nmax,-1));

ll ks(vector<int> &v, ll sum, ll i) {
	if (i == v.size()) {
		//if (sum > k)dp[i][k] = sum;
		//else dp[i][sum] = sum;

		return sum;
	}

	ll x = sum;
	if (x > k)x = k;
	if (dp[i][x] != -1 && dp[i][x] != 1e9)return dp[i][x];

	ll a = ks(v,sum + v[i],i+1);
	ll b = ks(v, sum, i + 1);

	if (abs(k - a) <= abs(k - b)) {

		if (a > k)dp[i][k] = min(dp[i][k],a);
		else dp[i][a] = a;
		return a;
	}

	if (b > k)dp[i][k] = min(dp[i][k],b);
	else dp[i][b] = b;
	return b;
	
}


ll solve()
{
	ll ans = 0;
	cin >> n >> k;
	vl v(n);
	fo(i, n)cin >> v[i];
	sort(v.rbegin(), v.rend());

	ll i = 0,suma = 0, sumb = 0, j=-1;
	while (i<n && suma < k) {
		suma += v[i++];
	}
	if (suma < k)return -1;

	j = i;
	while (j < n && sumb < k) {
		sumb += v[j++];
	}
	fo(i,n)set v[k] to 1e9
	ans = 1e9;//check this
	//if (suma >= k && sumb >= k)ans = j;
	if (sumb >= k)ans = j;

	ll jstart = i;

	i = 0;
	j--;
	ll jend = j;
	ll totala = suma;
	
	if (ans == 1e9) ans = -1;
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