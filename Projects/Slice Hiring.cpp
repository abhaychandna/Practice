#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<cmath>
using namespace std;


int prod(int x) {
    int res = 1;
    while (x) {
        res *= x % 10;
        x /= 10;
    }
    return res;
}

int sum(int x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int digcnt(int x) {
    int res = 0;
    while (x) {
        res = res + 1;
        x /= 10;
    }
    return res;
}

string smallest_number(int K) {
    // Write your code here
    int ans = 1e9;
    int end = 9;
    int cnt = 1;
    while (true) {
        if (((K - cnt) + (9 * cnt)) <= end) {
            break;
        }
        end = (end * 10) + 9;
        cnt++;
    }

    int start = 1;
    for (int i = 0; i < cnt - 1; i++)start = (start * 10) + 1;
    int min_prod = 1e9;
    end = 1e5;
    while (start <= end) {
        if (digcnt(start) > K)break;
        int x = (sum(start) + (K - digcnt(start)));
        int y = prod(start);
        //cout << start << " " << x << " " << end << "\n";
        if (x <= y) {
            if (y < min_prod)ans = start, min_prod = y;
            //cout<<start<<" "<<sum(start)<<" "<<prod(start)<<'\n';
            //ans = min(ans,start);
        }
        start++;
    }
    //cout<<start<<'\n';
    string s = "";
    cout << "A" << ans << '\n';
    for (int i = 0; i < K - cnt; i++)s += '1';
    s += to_string(ans);

    return s;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t_i = 0; t_i < T; t_i++)
    {
        int K;
        cin >> K;

        string out_;
        out_ = smallest_number(K);
        cout << out_;
        cout << "\n";
    }
}