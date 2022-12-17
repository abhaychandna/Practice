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

vl primes,fact;
const int sz = 1000;
vl prime(sz,1);
ll n;


void SieveOfEratosthenes(int n)
{
	
	for (int p = 2; p * p < n; p++)
	{
		
		
		if (prime[p] == true)
		{
			primes.pb(p);
			for (int i = p * p; i < n; i += p)
				prime[i] = false;
		}
	}

	
}

ll solve(ll f) {

	ll ans = 0;

	ll cur = fact[f];
	cur = n / cur;
	ll pre = fact[f - 1];
	pre = n / pre;
	ll total = pre - cur;
	ans += (total)*f;
	pre = cur;
	
	ans %= mod;
	return ans;
	//k++;
}


ll Ynot()
{
	ll ans = 0;
	//ll n;
	cin >> n;
	ll x;
	x = 1;
	ll k = 2;

	int id = 0;
	ll total = 0, cur = 0,pre= 0;

	pre = n / 2;
	k = 3;
	; // counting odd



	for (int i = 4; i <= (7560); i+=2) {
		for (int j = 2; j <= i; j++) {
			if (i%j != 0)
			{
				//if(j!=4)
				cout << i<< " "<<j << '\n'; 
				break;
			}
		}
	}

	/*for (ll i = 3; fact[i-1] <= n; i++) {

		int j = 0;
		while (j < primes.size() && primes[j] <= i) {
			ll d = primes[j], k = i;
			while (k > 1) {
				if (k % d != 0)break;
				k /= d;
			}
			if (k == 1) {
				ans += solve(i);
				break;
			}
			j++;
		}
		
	}*/


	//ans += ((n -1 1) / 2) * 2;
	ans = (n + 1) / 2;
	ans *= 2;
	ans %= mod;
	for (auto p : primes) {
		if (p == 2)continue;
		if (p > fact.size())
			break;
		ll u = solve(p);
		u %= mod;
		ans = (ans + u) % mod;
	}





	
	/*while (x <= 1e17) {
		cout << x << '\n';
		x = x * (k++);
	}*/
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fact.pb(1); 
	fact.pb(1); 
	for (int i = 2; i < 21; i++)
		fact.pb(fact[fact.size() - 1] * i);

	SieveOfEratosthenes(sz);
	int lm = 10,lm2=5;
	for (ll i = 2; i <= lm; i++)primes.pb(i * i);
	for(ll i = 2;i<=lm2;i++)primes.pb(i * i * i);
	sort(primes.begin(), primes.end());

	int t = 1;
	cin >> t;
	while (t--)
	{
		ll ans = 0;
		ans = Ynot();
		cout << ans << '\n';
	}
}