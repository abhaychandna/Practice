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

ll sz = 2005;


ll Ynot()
{
	ll ans = 0;
	ll n, k;
	cin >> n >> k;

	if (n % k != 0) {
		
		if (n < k)return -1;

		ll r = n%k;
		if (r % 2 == 1)return -1;
		int i = 1;
		for (i = 1; i + k-1 <= n; i += k) {
			string s = "? ";

			for (int j = i; j < i + k; j++) {
				s += to_string(j);
				s += " ";
			}
			cout << s << endl;
			ll x;
			cin >> x;
			ans = ans xor x;
		}
		
		int k2 = i;
		i = i - (k - (r / 2));
		int k = i; 
		int j = i + k;
		cout << "? ";
		while (i < j)cout << i++ << " ";
		ll x;
		cin >> x;
		ans = ans xor x;
		cout << "? ";
		while(k<k2)cout << k++ << " ";
		while (j < n)cout << j++ << " ";
		cin >> x;
		ans = ans xor x;

		return ans;

	}

	for (int i = 1; i+k-1<=n ; i += k) {
		string s = "? ";

		for (int j = i; j < i + k; j++) {
			s += to_string(j);
			s += " ";
		}
		cout << s << endl;
		ll x;
		cin >> x;
		ans = ans xor x;
	}
	return ans;
}

int main()
{
	int t = 1;
	//cin >> t;
	while (t--)
	{
		ll ans = 0;
		ans = Ynot();
		cout << ans << endl;
	}
}