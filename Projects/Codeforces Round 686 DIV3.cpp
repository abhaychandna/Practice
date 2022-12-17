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

#define vi vector<int>
#define vl vector<long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define fos(i,start,end,step) for(int i=start;i<end;i+=step)

using namespace std;

ll solve()
{
	ll ans = -1,ansi=-1;
	ll n;
	cin >> n;
	ll rn = sqrt(n);

	for(int i=2; i<=rn;i+= 1)
	{
		if (n % i == 0)
		{
			int cnt = 1;
			ll temp = n;

			n /= i;
			while (n % i == 0)
			{
				n /= i;
				cnt++;
			}

			if (cnt > ans)
			{
				ans = cnt;
				ansi = i;
			}
			n = temp;
		}
	}
	if (ans == -1)
	{
		cout << 1 << '\n' << n << '\n';
		return 0;
	}

	cout << ans << '\n';
	while (ans > 1)
	{
		cout << ansi << " ";
		n /= ansi;
		ans--;
	}
	cout << n <<'\n';
	return n;
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
		//cout << ans << '\n';
	}
}