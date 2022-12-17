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
#define vvi vector<vector<int>> 
#define vvl vector<vector<long long int>>
#define pi pair<int,int>
#define pl pair<long long int, long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define fon(i,start,end) for(int i=start;i<end;i++)
#define fos(i,start,end,step) for(int i=start;i<end;i+=step)

using namespace std;



ll solve()
{
	ll ans = 0;
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	if (n == 1)return s[0] - 'a';
	ll cnt = n / 2;
	if (n % 2)cnt++;
	cnt--;
	ll mid = cnt;

	vl v(cnt+1);
	ll x = k;
	v[0] = 1;
	for(int i = 1; i < v.size();i++) {
		v[i] = x;
		x = (x * k) % mod;
	}


	for (int i = 0; i <= mid; i++) {
		x = s[i] - 'a';
		ll sum = (x * v[cnt])%mod;
		ans = (ans + sum) % mod;
		cnt--;
	}
	int i,j;
	if (n%2!=0)i = mid - 1, j = mid + 1;
	else i = mid, j = mid + 1;

	bool b = false;
	while (i>=0) {
		if(s[i]==s[j])
			i--, j++;
		else
		{
			if (s[i] < s[j]) {
				b = true;
			}
			break;
		}
	}
	if (b)ans++;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t;i++)
	{
		ll ans = 0;
		ans = solve();
		cout << "Case #" << i << ": ";
		cout << ans << '\n';
	}
}