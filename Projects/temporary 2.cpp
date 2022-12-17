#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<cmath>
#include<math.h>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<random>
#include<unordered_map>
#include<unordered_set>
#include<fstream>
#include<iomanip>
#include<numeric>
#include<complex>
#include<climits>
#include <assert.h>
#include<list>
#define ll long long int
#define mod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define rep(i,n) for(int i=0;i<n;i++)
#define read(v,n) for(int i=0;i<n;i++)cin>>v[i];
#define print(v,n) for(int i=0;i<n;i++)cout<<v[i]<<" ";
#define pb push_back
#define fr first
#define se second
#define sz(s) (int)s.size()
#define all(x) x.begin(),x.end()
using namespace std;

string solve(string s) {
    int n = s.size(), i = 0;
    while (i < n && s[i] == 'a')i++;
    if ( i == n )return "imp";
    if (n % 2 && (i == n / 2))return "imp";
    s[i] = 'a';
    return s;
}


ll s(vector<pair<int, int>> v) {
    sort(v.begin(), v.end());
    ll ans = 0;
    int time = -1;
    for (auto x : v) {
        if (time <= x.first) {
            time=x.first+1;
            ans++;
            continue;
        }
        if (time <= x.second) {
            time++;
            ans++;
            continue;
        }
    }
    return ans;
}

ll rec(int i, vector<ll>& v, int &n, int &m, vector<ll>& f, vector<ll>&b, ll p, vector<vector<ll>>& dp, vector<vector<ll>> &ds) {
    if (i == n) {
        if (b[0] == 0) {
            for (int u = 0; u < n; u++) {
                cout << b[u] + 1 << " ";
            }
            cout << "\n";
        }
        return 1ll;
    }
    /*if (dp[i][p] != -1) {
        return dp[i][p];
    }*/
    ll total = 0;
    for (ll j = 0; j < m; j++) {
        bool flag = true;
        for (auto k : ds[i]) {
            if (b[k] == j)flag = false;
        }
        if (flag) {
            b[i] = j;
            total += rec(i + 1, v, n, m, f, b, j, dp, ds);
            total %= mod;
            b[i] = -1;
        }
    }
    return dp[i][p] = total;

}
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll>v(n);
    vector<ll>f(n, 0);
    vector<vector<ll>> ds(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
        ll a = i, b = v[i];
        if (a < b)swap(a, b);
        ds[a].pb(b);
        f[v[i]]++;
    }
    vector<ll>b(n, -1);
    vector<vector<ll>>dp(n + 2, vector<ll>(m + 2, -1));
    //cout << rec(0, v, n, m, f, b, 0, dp,ds) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s = "acca";
    int n = 10;
    for (int i = 0; i < 10;i++) {
        cin >> s;
        cout << solve(s);
    }return 0;
}