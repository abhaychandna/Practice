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
	ll n;
	ll s;
	cin >> n >> s;
	ll sum = 0;
	ll tempn = n;
	ll d2cnt = 0;
	while (n != 0)
	{
		sum += n % 10;
		n /= 10;
		d2cnt++;
	}
	n = tempn;
	ll red = 0;
	if (sum <= s)
		return 0;

	ll ml = 1;
	ans = 0;

	ll k = n;
	ll ktemp = k;
	ll ok = k;
	ml = 10;
	ll dcnt = 0;
	ll temp2k = k;
	red = 0;
	while (k / 10)
	{
		ll dig = k % 10;
		red += temp2k % 10;
		if (dig != 0)
		{

			ktemp -= (dig * (ml / 10));
			ktemp += ml;
			k -= dig * (ml / 10);
			k += ml;
			ans = ktemp - ok;
				
		}
		
		if (sum - red + 1 <= s)
		{
			ll x = pow(10, d2cnt);
			x = x - ok;
			return min(ans,x);
		}
		ml *= 10;
		k /= 10;
		temp2k /= 10;
		dcnt++;
	}

	dcnt++;
	ll ten = 10;
	ans = pow(ten, dcnt);
	return ans - ok;

	/*
	for (int i = n.size() - 1; i > 0; i--)
	{
		red += n[i] - '0';
		ll dig = n[i] - '0';
		ans += dig * ml;
		if (sum - red <= s)
		{
			return ans;
		}
	}
	return ans;*/
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
		ans = solve();
		cout << ans << '\n';
	}
}