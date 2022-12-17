#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);


/*
 * Complete the 'countOptions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER people
 *  2. INTEGER groups
 */

long long int solve(int n, int k, vector<vector<int, int>>& dp) {

    if (n == 0 && k == 0)return 1;
    if (n == 0 || k == 0)return 0;
    if (k > n)return 0;


    if (dp[n][k] != -1)
        return dp[n][k];

    long long int ans = 0;
    for (int i = 1; i < n; i++) {
        int left = n - i;
        ans += solve(left, k - 1, dp);
        for (int j = left - i - 1; j >= 0; j--) {
            ans -= solve(j, k - 2, dp);
        }
    }

    dp[i][j] = ans;
    return dp[i][j];
}


long countOptions(int people, int groups) {

    long long int ans = 0;

    int sz = 200;
    vector<vector<int>> dp(sz + 1, vector<int>(sz + 1, -1));

    for (int i = 1; i < sz; i++) {
        dp[i][i] = 1;
        dp[i][1] = 1;
        dp[0][i] = 0;
        dp[i][0] = 0;
    }

    return solve(n, k, dp);

    //return 0;

}
int main()