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
int sz = 1000001;
vi prime(sz, true),prmn(sz),prcnt(sz);
vl prsum(sz);

void sieve(int n) {
	n -= 1;
	prcnt[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (prime[i]) {
			prmn[i] = i;
			for (int j = 2 * i; j <= n; j += i) {
				if (prime[j])prmn[j] = i;
				prime[j] = false;
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		ll x = i;
		while (x != 1) {
			x /= prmn[x];
			prcnt[i]++;
		}
	}

	for (int i = 0; i <= 10; i++) {
		cout << i << " " << i << " " << i << " =6\n";
	}


}

ll solve()
{
	ll ans = 0;
	ll x, y;
	cin >> x >> y;



	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sieve(sz);
	
	for (int i = 1; i < prsum.size(); i++)prsum[i] = prsum[i-1] + prcnt[i];

	int t = 1;
	cin >> t;
	while (t--)
	{
		ll ans;
		ans = solve();
		cout << ans << '\n';
	}
}

