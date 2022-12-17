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
int rec(ll i, ll tt, vector<ll>& v, ll n, ll y, vector<vector<int>>& dp) {
    if (i == n && tt == y) {
        return 1;
    }
    if (i == n)
        return 0;
    if (dp[i][tt] != -1) {
        return dp[i][tt];
    }
    return dp[i][tt] = rec(i + 1, (tt + v[i]) & ((1 << 5) - 1), v, n, y, dp) | rec(i + 1, (tt ^ v[i]) & ((1 << 5) - 1), v, n, y, dp);
}
void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    n++;
    vector<ll>v(n);
    v[0] = x;
    v[0] &= ((1 << 5) - 1);
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        v[i] &= ((1 << 5) - 1);
    }
    y &= ((1 << 5) - 1);
    vector<vector<int>>dp(n + 5, vector<int>(1 << 6, -1));
    int ok = rec(0, 0ll, v, n, y, dp);
    if (ok == 1)cout << "Alice\n";
    else cout << "Bob\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}