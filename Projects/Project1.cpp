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

void pf(vector<ll> v) {
	fo(i, v.size())cout << v[i] << " ";
	cout << '\n';
}

bool sim(vector<ll> v) {

	vl v2 = v;
	int cnt = v.size(),left = v.size();
	int round = 100;
	
	while (round--) {
		for (int i = 0; i < v.size(); i++) {
			if (v[i] > 0) {
				v[i] -= cnt;
				if (v[i] <= 0)left--;
			}
		}
		cnt = left;
		if (left == 1)return false;
		if (left == 0) {
			pf(v2);
			return true;

		}
	}
	cout << "SIMUL FAILED!!";
	cout << "SIMUL FAILED!!";
	cout << "SIMUL FAILED!!";
	cout << "SIMUL FAILED!!";
	return false;
}

void c(){
	ll cnt = 0;
	for(int i=1;i<=4;i++)
		for (int j = 1; j <= 4; j++)
			for (int k = 1; k <= 4; k++)
				for (int m = 1; m <= 4; m++)
					for (int l = 1; l <= 4; l++) {
						//cout << i << " " << j << " " << k << " " << m<<" "<<l << '\n';

						vector<ll> v = { i,j,k,m,l };
						sort(v.begin(), v.begin() + 4);
						if (sim(v))cnt++;
						//if (v[4] == v[3])cnt++;
					}


	cout << "Cnt - " << cnt << '\n';
}

ll Ynot()
{
	ll ans = 0;
	ll n, m;
	cin >> n >> m;
	vvl v(n,vl(m));
	fo(i, n)fo(j, m)cin >> v[i][j];
	string yes = "YES\n", no = "NO\n";
	ll mn = 0, mx = 0;
	fo(i, n) {
		if (v[i][0] < v[mn][0])mn = i;
		if (v[i][0] > v[mx][0])mx = i;
	}
	ll mxid = mx, mnid = mn;

	vector<vector<vector<ll>>> r(n, vector<vector<ll>>(m, vector<ll>(2)));
	auto b=r;

	for (int i = 0; i < n; i++) {
		mx = -1;
		for (int j = 0; j < m; j++) {
			mx = max(mx, v[i][j]);
			r[i][j][0] = mx;
		}

		mx = -1;
		for (int j = m-1; j >=0; j--) {
			mx = max(mx, v[i][j]);
			r[i][j][1] = mx;
		}

		mn = 1e9;
		for (int j = 0; j < m; j++) {
			mn = min(mn, v[i][j]);
			b[i][j][0] = mn;
		}

		mn = 1e9;
		for (int j = m-1; j >=0 ; j--) {
			mn = min(mn, v[i][j]);
			b[i][j][1] = mn;
		}
	}



	mx = mxid, mn = mnid;
	int k = -1;
	for (int i = 0; i < m-1;i++) {
		if(b[mx][i][0]<=r[mn][i][0] || r[mx][i+1][1]>=b[mn][i+1][1])continue;
		//if (r[mx][i][0] <= b[mn][i][0] || b[mx][i][1]>=r[mn][i][1] )continue;
		k = i;
	}
	if (k == -1) {
		cout << no;
		return 1;
	}
	ll lmx=r[mx][k][0], lmn=b[mn][k][0], rmx=r[mn][k+1][1], rmn=b[mn][k+1][1];
	vector<char> z(n, '#');
	for (int i = 0; i < n; i++) {
		if (i == mxid || i == mnid)continue;
		if (r[i][k][0] >= lmx || b[i][k+1][1]<=rmx) {
			//red only

			if (b[i][k][0] <= lmn || r[i][k+1][1] >= rmn)
			{
				cout << no;
				return 1;
			}
			z[i] = 'R';

		}
		else if (b[i][k][0] <= lmn || r[i][k+1][1] >= rmn) {
			//blue only
			if (r[i][k][0] >= lmx || b[i][k+1][1] <= rmx) {
				cout << no;
				return 1;
			}
			z[i] = 'B';
		}

	}

	cout << yes;
	fo(i, n)cout << z[i];
	cout << " " << k << '\n';

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
		//cout << ans << '\n';
	}
}