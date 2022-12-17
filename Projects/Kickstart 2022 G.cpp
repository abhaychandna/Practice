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

ll solve(vl & v, ll i, ll j) {
	ll cnt = 0;
	ll sum = 0;
	while (i <= j) {
		sum += v[i++];
		if (sum < 0)break;
		cnt++;
	}
	return cnt;
}
ll Ynot()
{
	ll ans = 0;
	
	ll n;
	cin >> n;
	vl v(n);
	fo(i, n)cin >> v[i];
	
	for (int i = n - 1; i >= 0; i--) {
		if (v[i] < 0)continue;
		
		ll sum = v[i];
		ans += v[i];
		
		int j = i + 1;
		while (j < n && v[j] < 0) {
			sum += v[j];
			if (sum < 0) {
				break;
			}
			ans += sum;
			j++;
		}
	}
	
	fo(i, n) {
		int j = i;
		ll sum = 0;
		while (j < n) {
			sum += v[j];
			if (sum < 0)break;
			ans += sum;
			j++;
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
	for (int i = 1; i <= t; i++) {
		auto ans = Ynot();
		cout << "Case #" << i << ": " << ans << endl;
	}
}