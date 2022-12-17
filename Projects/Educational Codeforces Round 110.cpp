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

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}


ll Ynot()
{
	ll ans = 0;
	string s;
	cin >> s;
	ll n = s.size();
	int i = 0, start = 0,end = -1,k=0,kid;
	while (i < n && s[i] == '?')i++;
	if (i == n) {
		start = 0, end = n - 1;
		k = end - start + 1;
		ans += ((k) * (k + 1)) / 2;
		return ans;
	}
	
	kid = i;
	end = i;
	i++;
	

	
	for (; i < n; i++) {
		if ((s[i] == '0' && s[i - 1] == '1') || (s[i] == '1' && s[i - 1] == '0')) {
			end = i;
			continue;
		}

		else if (s[i] == '?') {

			int qs = i, qe = -1;
			while (i < n && s[i] == '?')i++;
			end = i-1, qe = i;

			if (i == n) {
				end = n - 1;
				k = end - start + 1;
				ans += ((k) * (k + 1)) / 2;
				ans -= k;
				start = n, end = n;
				break;
			}

			if ((((i - kid) % 2 == 0) && s[i] == s[kid]) || (((i - kid) % 2 == 1) && s[i] != s[kid]))
			{
				end = i;
				continue;
			}
			else {
				k = end - start + 1;
				ans += ((k) * (k + 1)) / 2;
				
				int x = k,cnt=0;
				//while (x <= end)if (s[x++] != '?')cnt++;

				start = qs;
				k = end - start + 1;
				ans -= ((k) * (k + 1)) / 2;

				ans -= (x - k);

				start = qs, end = i,kid = i;

			}

		}
		else {
			k = end - start + 1;
			ans += ((k) * (k + 1)) / 2;
			ans -= k;
			start = i, end = i,kid = i;

		}
	}
	
	if (start < n) {
		k = end - start + 1;
		ans += ((k) * (k + 1)) / 2;
		ans -= k;
	}

	/*
	for (int i = 0; i < n;) {
		while (i < n && s[i] != '?')i++;
		if (i == n)break;

		start = i;
		while (i < n && s[i] == '?')i++;
		end = i - 1;

		
			k = end - start + 1;
			ans += ((k) * (k + 1)) / 2;
			ans -= k;
		
	}
	*/
	ans += n;
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
		ll ans = 0;
		ans = Ynot();
		cout << ans << '\n';
	}
}