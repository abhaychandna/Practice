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
ll N = 100001;
// array to store inverse of 1 to N 
vl factorialNumInverse(N+1);

// array to precompute inverse of 1! to N! 
vl naturalNumInverse(N+1);

// array to store factorial of first N numbers 
vl fact(N+1);

// Function to precompute inverse of numbers 
void InverseofNumber(ll p)
{
	naturalNumInverse[0] = naturalNumInverse[1] = 1;
	for (int i = 2; i <= N; i++)
		naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials 
void InverseofFactorial(ll p)
{
	factorialNumInverse[0] = factorialNumInverse[1] = 1;

	// precompute inverse of natural numbers 
	for (int i = 2; i <= N; i++)
		factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}

// Function to calculate factorial of 1 to N 
void factorial(ll p)
{
	fact[0] = 1;

	// precompute factorials 
	for (int i = 1; i <= N; i++) {
		fact[i] = (fact[i - 1] * i) % p;
	}
}

// Function to return nCr % p in O(1) time 
ll Binomial(ll N, ll R, ll p)
{
	// n C r = n!*inverse(r!)*inverse((n-r)!) 
	ll ans = ((fact[N] * factorialNumInverse[R])
		% p * factorialNumInverse[N - R])
		% p;
	return ans;
}


ll solve()
{
	ll ans = 0;
	ll n, m;
	cin >> n >> m;
	vi v(n - 1);
	vi freq(n);
	fo(i, n - 1)
	{
		cin >> v[i];
		freq[v[i]]++;
	}
	//sort(v.begin(), v.end());
	//freq[1] = 1;
	ans = 1;
	for (int i = 2; i < n; i++)
	{
		if (freq[i] > freq[i - 1])
		{
			return 0;
		}
		ans *= Binomial(freq[i - 1], freq[i], mod);
		ans %= mod;
	}


	return ans;
}

int main()
{

	ll p = 1000000007;
	InverseofNumber(p);
	InverseofFactorial(p);
	factorial(p);

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