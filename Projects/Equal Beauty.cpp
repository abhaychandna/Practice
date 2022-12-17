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

ll minCost(vector<ll>& A)
{

    ll n = A.size();
    ll cost = 0;
    ll K = A[n / 2];
    for (int i = 0; i < n; ++i)
        cost += abs(A[i] - K);
    if (n % 2 == 0) {
        ll tempCost = 0;
        K = A[(n / 2) - 1];
        for (int i = 0; i < n; ++i)
            tempCost += abs(A[i] - K);

        cost = min(cost, tempCost);
    }

    return cost;
}

void solve() {

    ll ans = 0;
    vector<ll> k1, k2;

    ll n;
    cin >> n;
    vector<ll>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }


    sort(v.begin(), v.end());
    k1.assign(v.begin() + 1, v.end());
    k2.assign(v.begin(), v.end() - 1);
    ans = min(minCost(k1), minCost(k2));

    for (int i = 1; i < n - 1; i++) {
        int r = i;
        ll diff = v[r] - v[0];
        ll k = v[n - 1] - diff;
        ll id = lower_bound(v.begin(), v.end(), k) - v.begin();

        int step = 5;
        for (int j = max((ll)1,id - step); j <= min(n-1,id + step); j++) {
            if (j == 0 || j==r || j==n-1)continue;
            if (j > r + 1)break;
            ans = min(ans, abs(diff - (v[n - 1] - v[j])));
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}