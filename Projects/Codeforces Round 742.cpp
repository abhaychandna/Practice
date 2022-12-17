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

ll ans = 0;
ll s, n;

bool check(map<ll, ll> cnt, ll s) {
	ll k = 0;
	for (auto it : cnt) {
		ll a = it.first, b = it.second;
		while (b--) {
			s -= a;
			//cout << a << " ";
			k++;
		}
	}
	if (s != 0) {
		//cout << s;
		k++;
	}//cout << '\n';
	//cout << ((k != n) ? "DIFF\n" : "SAME\n");

	return (k==n);
}

void solve(map<ll, ll> cnt, ll s) {
	ll k = 0;
	for (auto it : cnt) {
		ll a = it.first, b = it.second;
		while (b--) {
			s -= a;
			cout << a << " ";
			k++;
		}
	}
	if (s != 0) {
		cout << s;
		k++;
	}cout << '\n';
	//cout << ((k != n) ? "DIFF\n" : "SAME\n");

	return;
}


ll Ynot()
{
	cin >> s >> n;

	map<ll, ll> cnt;
	if (n == 1) {
		cnt[s]++;
		solve(cnt, s);
		return 0;
	}
	ans = 0;

	ll temp = s;
	ll id = 1;
	bool flag = true;
	while (flag && s>0) {
		ll den = 10;
		ll x = s % den;
		for (int i = 0; i < x; i++) {
			cnt[id]++;
			ans++;
			if (n == ans) {
				
				if (!check(cnt, temp))
					cnt[id]--;
				solve(cnt, temp);
				
				flag = false;
				return 0;
			}
		}
		s /= 10;
		id *= 10;
	}


	for (auto it : cnt) {
		ll a = it.first, b = it.second;
		if (a == 1)continue;
		if (a == 10) {
			for (int k = 0; k < b; k++) {
				if (ans + 9 < n) {
					cnt[a]--;
					cnt[1] += 10;
					ans += 9;
				}
				else {
					ll req = n - ans;
					cnt[a]--;
					cnt[a - req]++;
					cnt[1] += req;
					solve(cnt, temp);
					return 0;
				}
			}
			continue;
		}

		while (true) {
			
			while (a >= 100) {
				if (ans + 9 < n) {
					cnt[a]--;
					cnt[a/10] += 10;
					a /= 10;
					ans += 9;
				}
				else {
					ll req = n - ans;
					cnt[a]--;
					ll k = (a / 10) * (10 - req);
					cnt[k]++;
					cnt[a/10] += req;
					solve(cnt, temp);
					return 0;
				}		

			}

			b = cnt[10];
			for (int k = 0; k < b; k++) {
				if (ans + 9 < n) {
					cnt[a]--;
					cnt[1] += 10;
					ans += 9;
				}
				else {
					ll req = n - ans;
					cnt[a]--;
					cnt[a - req]++;
					cnt[1] += req;
					solve(cnt, temp);
					return 0;
				}
			}


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
	while (t--)
	{
		ll p = 0;
		p = Ynot();
		//cout << ans << '\n';
	}
}