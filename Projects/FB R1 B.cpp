#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<fstream>

#define ll long long 
#define mod 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

#define vi vector<int>
#define vl vector<long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define fos(i,start,end,step) for(int i=start;i<end;i+=step)

ll check()
{ 

}

using namespace std;

ll solve()
{
	ll ans = 0;
	ll n, m, k,s;
	cin >> n >> m >> k >> s;
	vl p(k),q(k);
	fo(i, k)cin >> p[i];

	ll al, bl, cl, dl;
	cin >> al >> bl >> cl >> dl;
	al %= dl;
	bl %= dl;
	cl %= dl;

	fo(i,k)cin >> q[i];

	ll ah, bh, ch, dh;

	cin >> ah >> bh >> ch >> dh;
	ah %= dh;
	bh %= dh;
	ch %= dh;

	while (k < n)
	{
		ll lsum = 0, hsum = 0;
		lsum = (((p[k - 2]) % dl) * al) % dl;
		lsum += (((p[k - 1]) % dl) * bl) % dl;
		lsum %= dl;
		lsum += cl;
		lsum %= dl;
		lsum++;
		p.pb(lsum);

		hsum = (((q[k - 2]) % dh) * ah) % dh;
		hsum += (((q[k - 1]) % dh) * bh) % dh;
		hsum %= dh;
		hsum += ch;
		hsum %= dh;
		hsum++;
		q.pb(hsum);

		k++;
	}

	sort(p.begin(), p.end());
	sort(q.begin(), q.end());

	check();

	return ans;
}

int main()
{
	//freopen("A1.txt", "r", stdin);
	//freopen("A1op.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		ll z = 0;
		char x = '0' + i;
		string ans = "Case #";
		ans += to_string(i);
		ans += ": ";
		cout << ans;
		z = solve();
		cout << ans << z << '\n';
		//cout << ans<<z << '\n';
	}
}