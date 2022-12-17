#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {

    sort(nums.begin(), nums.end());
    int n = nums.size();

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int left = j + 1, right = n - 1;
            int sum = target - nums[i] - nums[j];

            while (left < right) {

                if (sum > nums[left] + nums[right])left++;
                else if (sum < nums[left] + nums[right])right--;
                else {
                    ans.push_back({ nums[i],nums[j],nums[left],nums[right] });

                    left++;
                    while (left < right && nums[left - 1] == nums[left])left++;

                    right--;
                    while (left < right && nums[right + 1] == nums[right])right--;

                }

            }

            while (j + 1 < n && nums[j] == nums[j + 1])j++;
        }
        while (i + 1 < n && nums[i] == nums[i + 1])i++;
    }

    return ans;


}

int main()
{
    vector<int> v = { 1,0,-1,0,-2,2 };
    auto x = fourSum(v,0);
    for (auto k : x) {
        for (int i = 0; i < k.size(); i++)cout << k[i] << " ";
        cout << '\n';
    }
    return 0;
}
