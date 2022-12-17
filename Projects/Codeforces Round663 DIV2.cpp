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

ll solve()
{
	ll n;
	cin >> n;
	//if (n == 3)
		//return 2; // check!
	if (n == 1 || n == 2)
	{
		cout << 0 << '\n';
		return 0;
	}ll fact = 1;
	for (int i = 1; i <= n; i++)
		fact = (fact * i) % mod;
	n--;
	ll two = 1;
	for (int i = 0; i < n; i++)
		two = (two * 2) % mod;
	fact = (fact - two) % mod;//overflow ? 
	cout << fact << '\n';
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t=1;
	//cin >> t;
	while (t--)
	{
		ll ans = 0;
		ans = solve();
		//cout << ans << '\n';
	}
}