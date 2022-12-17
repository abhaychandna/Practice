#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;

int merge(vector<int>& v, int start, int mid, int end) {

    int count = 0;
    int i, j;
    for (i = start, j = mid + 1; i <= mid; i++) {
        while (j <= end && (v[i] > 2LL * v[j]))j++;
        count += j - (mid + 1);
    }

    vector<int> tmp(end - start + 1);
    int k;

    i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end) {
        if (v[i] < v[j])tmp[k++] = v[i++];
        else tmp[k++] = v[j++];
    }
    while (i <= mid)tmp[k++] = v[i++];
    while (j <= end)tmp[k++] = v[j++];

    i = start, k = 0;
    while (i <= end)v[i++] = tmp[k++];

    return count;

}

int mergeSort(vector<int>& v, int start, int end) {

    if (start == end) return 0;

    int count = 0, mid = (start + end) / 2;
    count = mergeSort(v, start, mid);
    count += mergeSort(v, mid + 1, end);

    count += merge(v, start, mid, end);

    return count;
}

int reversePairs(vector<int>& nums) {

    return mergeSort(nums, 0, nums.size() - 1);

}

int main()
{
    vector<int> v = { 1,3,2,3,1 };
    cout << reversePairs(v);
    return 0;
}
