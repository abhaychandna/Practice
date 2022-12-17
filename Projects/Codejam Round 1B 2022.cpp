#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<cmath>
#include <bitset>


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

ll solve()
{
	ll ans = 0;
	ll x = 0, f = (pow(2, 8) - 1);
	bitset<8> start(0), full(511), one(1), two(3), three(7), four(15), k;
	bitset<8> cstm(210);
	cout << cstm;
	while (true) {
		cin >> x;
		if (x == -1)return -1;
		if (x == 0)return 0;
		if (x == 8) k = full;
		else {
			if (x == 6 || x == 2) k = two;
			else if (x == 4) k = four;
			else k = one;
		}
		cout << k;
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		ll ans = solve();
		if (ans == -1)return 0;
		//cout << "Case #" << i << ": " << ans << endl;
	}
}