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

bool ck(vl v,int i) {
	return ((v[i] ^ v[i+1]) > 0) ? 0 : -1;
}

ll Ynot()
{
	ll ans = 0;
	ll n;
	cin >> n;
	vl v(n);
	int id = -1;
	fo(i, n) {
		cin >> v[i];
		if (v[i] != 0)id = i;
	}
	if (n == 1)return 0;
	if (n == 2)
		return ((v[0] ^ v[1]) > 0) ? 0 : -1;
	if (n == 3) {
		return (ck(v, 0) && ck(v, 1) && ((v[0] ^ v[1] ^ v[2]) == v[1])) ? 0 : -1;
	}

	if (id == -1)return -1;

	int p = id%2;
	
	int i, j, k;//init j
	k = 0;
	if (id == 0) k = 1;

	ll elem = v[k] ^ v[j];

	for (int i = 0; i < n; i++) {
		if (i % 2 == p)continue;

		v[i] = elem;


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
		ll ans = 0;
		ans = Ynot();
		cout << ans << '\n';
	}
}