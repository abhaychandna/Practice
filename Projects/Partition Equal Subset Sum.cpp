#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;


bool canPartition(vector<int>& nums) {

    int n = nums.size();
    int m = 0;
    for (auto val : nums)m += val;
    if (m % 2)return false;

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));

    for(int i=0;i<n;i++)dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i-1][j];
            if (j < nums[i - 1])continue;
            dp[i][j] = max(dp[i][j], dp[i-1][j - nums[i - 1]]);
        }
    }

    return dp[n][m / 2];

}

int main()
{
    vector<int> v = { 1,5,11,5};
    canPartition(v);
    return 0;
}

