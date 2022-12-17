#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;

void calcSubsets(vector<int>& nums, int id, vector<vector<int>>& res, vector<int>& tmp) {

    res.push_back(tmp);
    for (int i = id; i < nums.size(); i++) {
        if (i != id && nums[i] == nums[i - 1])continue;
        tmp.push_back(nums[i]);
        calcSubsets(nums, i + 1, res, tmp);
        tmp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {

    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> tmp;

    calcSubsets(nums, 0, res, tmp);

    return res;

}

int main()
{
    vector<int> v = {1,2,2};
    subsetsWithDup(v);
    return 0;
}
