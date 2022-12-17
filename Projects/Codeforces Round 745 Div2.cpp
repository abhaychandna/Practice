#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<cmath>

#define ll int
#define mod 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

#define vl vector<long long int>
#define pl pair<long long int, long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define forev(i,n) for(int i=n-1;i>=0;i--)

using namespace std;

const int sz = (2 * (1e5)) + 10;
vl fact(sz),fact2(sz);

ll chk(vector<vector<bool>> & v, vector<vector<int>> &pre, vector<vector<int>> &d, vector<vector<int>> &tl, int i1, int j1, int i2, int j2,int n, int m) {
	ll ans = 0;
	ll a = i2 - i1+1, b = j2 - j1+1;
	ans += b-2 - ((pre[i1][j2] - pre[i1][j1]) - v[i1][j2]);
	ans += b-2 - ((pre[i2][j2] - pre[i2][j1]) - v[i2][j2]);

	ans += a-2 - ((d[i2][j1] - d[i1][j1]) - v[i2][j1]);
	ans += a-2 - ((d[i2][j2] - d[i1][j2]) - v[i2][j2]);

	//ans += v[i1][j1] + v[i2][j1] + v[i1][j2] + v[i2][j2];

	i2--, j2--, i1++, j1++;
	ll k = 0;
	if (j1 - 1 >= 0)k += tl[i2][j1 - 1];
	if (i1 - 1 >= 0)k += tl[i1 - 1][j2];
	if ((i1 - 1 >= 0) && (j1 - 1 >= 0)) k -= tl[i1 - 1][j1 - 1];
	ans += tl[i2][j2] - k;
	//ans += tl[i2][j2] - tl[i2][j1] - tl[i1][j2] + tl[i1][j1];

	return ans;
}

ll Ynot()
{
	int ans = 20;
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> v(n, vector<bool>(m));
	fo(i, n) {
		string s;
		cin >> s;
		fo(j, m)v[i][j] = s[j] - '0';
	}

	vector<vector<int>> pre(n, vector<int>(m));
	vector<vector<int>> d = pre, tl = pre;
	fo(i, n) {
		int cnt = 0;
		fo(j, m) {
			cnt += v[i][j];
			pre[i][j] = cnt;
		}
	}
	fo(j, m) {
		int cnt = 0;
		fo(i, n) {
			cnt += v[i][j];
			d[i][j] = cnt;
		}
	}

	tl[0] = pre[0];
	fo(i, n)tl[i][0] = d[i][0];

	fo(i, n) {
		fo(j, m) {
			if (i == 0 || j == 0)continue;
			tl[i][j] = tl[i - 1][j - 1] + pre[i][j] + d[i][j] - v[i][j];
		}
	}

	fo(i, n-4) {
		fo(j, m-3) {
			for (int k = i + 4; k < n; k++) {
				int old = -1;
				for (int l = j + 3; l < m; l++) {
					int x = chk(v, pre, d, tl, i, j, k, l, n, m);
					ans = min(ans, x);
					if (old == -1) old = x;
					old += !v[i][l];
					old += !v[k][l];
					old += d[k - 1][l] - d[i][l];
					if (old >= 20)
						break;
					//ans = min(ans, chk(v, pre, d, tl, i, j, k, l, n, m));
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
		ll ans = 0;
		ans= Ynot();
		cout <<ans << '\n';
	}
}