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
#include <assert.h>
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

ll gcd(ll A, ll B)
{
    if (B == 0)
        return A;
    else
        return gcd(B, A % B);
}
void build(vector<ll>& a, ll v, ll tl, ll tr, vector<ll>& t) {
    if (tl == tr) {
        t[v] = a[tl];
    }
    else {
        ll tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm, t);
        build(a, v * 2 + 1, tm + 1, tr, t);
        t[v] = gcd(t[v * 2], t[v * 2 + 1]);
    }
}
ll g(ll v, ll tl, ll tr, ll l, ll r, vector<ll>& t) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return gcd(g(v * 2, tl, tm, l, min(r, tm), t), g(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, t));
}


bool check(ll n, ll mid, vector<ll>& t) {

    for (ll i = 0; i <= n - mid; i++) {
        cout << g(i, 0, n - 1, i, i + mid - 1, t) << " " << mid << "\n";
        if (g(i, 0, n - 1, i, i + mid - 1, t) != 1) {
            return true;
        }
    }
    return false;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll>v(n);
    read(v, n);
    vector<ll>t(4 * n);
    vector<ll>a(n - 1);
    for (int i = 0; i < n - 1; i++) {
        a[i] = abs(v[i] - v[i + 1]);
    }
    build(a, 1, 0, n - 2, t);
    int l = -1;
    int r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(n - 1, mid, t)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << l + 1 << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}