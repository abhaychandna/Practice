#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;

class Solution {

private:
    vector<long long > calc(vector<long long> pre, vector<int> cur) {
        int n = pre.size();
        vector<long long> res(n);

        res[0] = pre[0];

        for (int i = 1; i < n; i++) {
            res[i] = max(res[i - 1] - 1, pre[i]);
        }

        return res;

    }

public:
    long long maxPoints(vector<vector<int>>& points) {

        int n = points.size(), m = points[0].size();

        vector<long long> pre;
        for (auto x : points[0])pre.push_back(x);

        vector<long long> left, right;

        for (int i = 1; i < n; i++) {

            left = calc(pre, points[i]);
            reverse(pre.begin(), pre.end());
            reverse(points[i].begin(), points[i].end());
            right = calc(pre, points[i]);
            reverse(pre.begin(), pre.end());
            reverse(points[i].begin(), points[i].end());

            reverse(right.begin(), right.end());

            for (int j = 0; j < m; j++)
                pre[j] = points[i][j] + max(left[j], right[j]);
        }

        return *max_element(pre.begin(), pre.end());

    }
};


int main()
{
    vector<vector<int>> v = { {1,2,3} ,{1,5,1},{3,1,1} };
   
    Solution s;
    cout << s.maxPoints(v);
    return 0;
}