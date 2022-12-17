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

ll d = 10;
ll mulexp(ll n, vector<vector<ll>> & adj, vector<ll> & v) {
    vector<vector<ll>>id(10, vector<ll>(10, 0));
    for (int i = 0; i < 10; i++)id[i][i] = 1;
    ll tmp[10][10] = { 0 };
    ll i, j, k;
    while (n) {
        if (n & 1) {
            memset(tmp, 0ll, sizeof(tmp));
            for (i = 0; i < d; i++)
                for (j = 0; j < d; j++)
                    for (k = 0; k < d; k++) {
                        tmp[i][j] = (tmp[i][j] + ((id[i][k] * adj[k][j]) % mod));
                        tmp[i][j] %= mod;
                    }

            for (i = 0; i < d; i++)
                for (j = 0; j < d; j++)
                    id[i][j] = tmp[i][j];

        };
        memset(tmp, 0, sizeof(tmp));
        for (i = 0; i < d; i++)
            for (j = 0; j < d; j++)
                for (k = 0; k < d; k++) {
                    tmp[i][j] = (tmp[i][j] + ((adj[i][k] * adj[k][j]) % mod));
                    tmp[i][j] %= mod;
                }

        for (i = 0; i < d; i++)
            for (j = 0; j < d; j++)
                adj[i][j] = tmp[i][j];

        n /= 2;
    };
    ll ans = 0;
    for (int j = 0; j < 10; j++) {
        for (int p = 0; p < 10; p++) {
            ans += ((id[j][p] * v[j]) % mod);
            ans %= mod;
        }
    }
    return ans;

};

int calcLength(int n, int m, int k) {
    ll ans = 0;
    string s = to_string(n);
    vector<ll>v(10, 0);
    for (int i = 0; i < s.size(); i++)
        v[s[i] - '0']++;
    vector<vector<ll>>adj(10, vector<ll>(10, 0));
    for (int i = 0; i < 10; i++) {
        ll y = i + k;
        if (y == 0) adj[i][0]++;
        while (y) {
            ll rem = y % 10;
            y /= 10;

            adj[i][rem]++;
        }
    }
    ans = mulexp(m, adj, v);
    return ans;
    //cout<<mulexp(m,adj,v)<<"\n";
}


ll Ynot()
{
    ll ans = 0;
    ll n, m, k;
    cin >> n >> m >> k;
    ans = calcLength(n, m, k);
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