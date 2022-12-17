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



ll solve()
{

	ll ans = 0;
	ll n, m;
	cin >> n >> m;
	ll a=0, b=0;

	if (n == m) {
		if (n % 2 == 0) {
			a = 
		}
		else {
			b = m / 2;

			a = m / 2;
			if (m % 2)
			{
				b++;
				a = n - m / 2;
			}
		}
	}
	else if (n > m ) {

		b = m / 2;
		
		a = m/2;
		if (m % 2)
		{
			b++;
			a = n - m / 2;
		}

	}
	else if (m > n) {
		swap(m, n);
		b = n / 2;

		a = m / 2;
		if (m % 2)
		{
			b++;
			a = n - m / 2;
		}

	}

	cout << a << " " << b<<'\n';



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