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
#define print(v,n) for(int i=0;i<n;i++)cout<<v[i]<<", ";
#define pb push_back
#define fr first
#define se second
using namespace std;
int n, m;
int cal(vector<vector<pair<int, int>>>& v, int val, int k) {

    vector<vector<pair<int, int>>>dp(n, vector<pair<int, int>>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j].first = (v[i][j].first == (val));
                dp[i][j].second = v[i][j].second;
                continue;
            }
            else if (v[i][j].first == (val ^ 1)) {
                dp[i][j].first = 0;
                dp[i][j].second = v[i][j].second;
            }
            else {
                int max1 = v[i][j].second;
                dp[i][j].first = 1 + min({ dp[i - 1][j].first,dp[i][j - 1].first,dp[i - 1][j - 1].first });
                if (dp[i][j].first != 1) {
                    if (dp[i][j].first - 1 == dp[i - 1][j].first) {
                        max1 = max(max1, dp[i - 1][j].second);
                    }
                    if (dp[i][j].first - 1 == dp[i][j - 1].first) {
                        max1 = max(max1, dp[i][j - 1].second);
                    }
                    if (dp[i][j].first - 1 == dp[i - 1][j - 1].first) {
                        max1 = max(max1, dp[i - 1][j - 1].second);
                    }
                }
                dp[i][j].second = max1;
            }
        }
    }
    int mp = mod;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j].first == k) {
                int t = 0;
                for (int p = i; p > i - k; p--) {
                    //cout << p << " ";
                    for (int y = j; y > j - k; y--) {
                        t = max(t, v[p][y].second);
                    }
                }
                mp = min(mp, t);
                //cout << "\n";
            }
        }
    }


    return mp;
}

void solve() {
    int k;
    cin >> n >> m >> k;
    int ans = 0;
    vector<vector<pair<int, int>>>v(n, vector<pair<int, int>>(m));
    int t = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            if (t % 2 == 0)
                v[a][b].first = (t % 2);
            else {
                v[a][b].first = (t % 2);
            }
            v[a][b].second = t + 1;
            t++;
        }
    }
    int y1 = cal(v, 0, k);
    int y2 = cal(v, 1, k);
    //cout << y1 << " " << y2 << "\n";
    if (y1 == mod && y2 == mod) {
        cout << "Draw\n";
    }
    else if (y1 == mod) {
        cout << "Bob\n";
    }
    else if (y2 == mod) {
        cout << "Alice\n";
    }
    else if (y1 < y2) {
        cout << "Alice\n";
    }
    else {
        cout << "Bob\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}