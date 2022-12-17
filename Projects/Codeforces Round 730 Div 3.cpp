#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define read(i,n,v) for(int i=0;i<n;++i) cin>>v[i];
#define IOF ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1e9+7
#define N 1000006
using namespace std;


void solution() {
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> v(n), p(m), ans;
    rep(i, 0, n - 1) cin >> v[i];
    rep(i, 0, m - 1) cin >> p[i];

    int pol = 0;
    int mono = 0;
    int len = k;
    bool flag = false;
    rep(i, 0, n + m - 1) {

        if (v[mono] <= len || v[mono] == 0) {
            ans.push_back(v[mono]);
            if (v[mono] == 0)
                len++;
            mono++;

        }
        else if (p[pol] <= len || p[pol] == 0) {

            ans.push_back(p[pol]);
            if (p[pol] == 0) len++;
            pol++;
        }
        else {
            flag = true;
            break;
        }

    }

    int sz = (int)ans.size();
    if (flag || sz != n + m) {
        cout << "-1\n";
        return;
    }
    rep(i, 0, n + m - 1)	cout << ans[i] << " ";
    cout << "\n";

}


int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

    IOF
        int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        //cout<<"Case #"<<i<<": ";
        solution();
    }
}