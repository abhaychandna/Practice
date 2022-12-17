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


vector<ll> cb(ll n,ll base) {
	vector<ll> res;

	while (n) {
		res.push_back(n % base);
		n /= base;
	}
	return res;
}

ll toDec(vl v, ll base) {
	ll res=0;

	fo(i, v.size()) {
		res += pow(base, i) * v[i];
	}
	return res;
}


vl calcXor(ll n,ll base) {

	vl v1, v2;
	v1 = cb(n,base);
	v2 = cb(n - 1,base);
	while (v1.size() < v2.size())v1.push_back(0);
	while (v2.size() < v1.size())v2.push_back(0);

	vl res(v1.size());
	fo(i, res.size()) {
		res[i] = (v1[i] + v2[i]) % base;
	}
	return res;
}

ll Ynot()
{
	ll ans = 0;
	ll n, k;
	cin >> n >> k;

	ll i = 0;
	i = 0;
	ll r=0;

	cout << i << endl;
	cin >> r;
	if (r == 1)return 0;

	ll cnt = 1;
	while (cnt<n) {
		vl res = calcXor(cnt,k);//cnt & cnt - 1;
		i = toDec(res, k);
		cout << i << endl;
		cin >> r;
		if (r == 1)return 0;
		i++;
		cnt++;
	}

	return 1;
	
	return ans;
}

int main()
{

	int t = 1;
	cin >> t;	
	while (t--)
	{
		ll ans = 0;
		ans = Ynot();
		if (ans == 1)break;
		//cout << ans << endl;
	}
}