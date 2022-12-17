#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;


vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    int n = nums.size();
    vector<int> ans;
    deque<int> dq;

    for (int i = 0; i < n; i++) {
            while (!dq.empty() && dq.front() < i - k + 1)dq.pop_front();
            while (!dq.empty() && nums[dq.back()] <= nums[i])dq.pop_back();
            dq.push_back(i);
        
        if(i>=k)ans.push_back(nums[dq.front()]);
    }
    return ans;
}
int main()
{
    vector<int> v = { 1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = maxSlidingWindow(v, k);
    for (auto val : res)cout << val << " ";
    return 0;
}



