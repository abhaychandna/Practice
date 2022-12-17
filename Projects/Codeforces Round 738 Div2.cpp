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

ll MAXN = 1000;
vl par1(MAXN + 10);
vl sz1(MAXN + 10);
vl par2(MAXN + 10);
vl sz2(MAXN + 10);

int find(int u)
{
    if (u == par1[u])
        return u;

    else
        return  find(par1[u]);
}

void combine(int u, int v)
{
    u = find(u);
    v = find(v);

    if (u == v)
        return;

    else
    {
        if (sz1[u] > sz1[v])
        {
            par1[v] = u;
            sz1[u] += sz1[v];
        }

        else
        {
            par1[u] = v;
            sz1[v] += sz1[u];
        }

    }
}


int find2(int u)
{
    if (u == par2[u])
        return u;

    else
        return  find2(par2[u]);
}

void combine2(int u, int v)
{
    u = find2(u);
    v = find2(v);

    if (u == v)
        return;

    else
    {
        if (sz2[u] > sz2[v])
        {
            par2[v] = u;
            sz2[u] += sz2[v];
        }

        else
        {
            par2[u] = v;
            sz2[v] += sz2[u];
        }

    }
}

ll Ynot()
{
    ll ans = 0;
    ll n;
    cin >> n;
    ll m1, m2;
    cin >> m1 >> m2;

    vector<pl> k;

    for (int i = 0; i < n; i++) {
        par1[i + 1] = i + 1;
        sz1[i + 1] = 1;
        par2[i + 1] = i + 1;
        sz2[i + 1] = 1;
    }
    fo(i, m1)
    {
        ll x, y;
        cin >> x >> y;

        combine(x, y);
    }
    fo(i, m2) {
        ll x, y;
        cin >> x >> y;

        combine2(x, y);
    }

    for (int i = 1; i <= 1; i++) {
        for (int j = 1; j <= n; j++) {
            if (find(i) == find(j))continue;
            if (find2(i) == find2(j))continue;

            ans++;
            k.pb({ i,j });
            combine(i, j);
            combine2(i, j);
        }
    }

    cout << k.size()<<'\n';
    fo(i, k.size()) {
        cout << k[i].first << " " << k[i].second << '\n';
    }

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	//cin >> t;
	while (t--)
	{
		ll ans = 0;
		ans = Ynot();
		//cout << ans << '\n';
	}
}