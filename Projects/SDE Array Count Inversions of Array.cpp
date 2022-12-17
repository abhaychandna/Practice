#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<cmath>

#define ll long long 
#define mod 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define vl vector<long long int>
#define vvl vector<vector<long long int>>
#define pl pair<long long int, long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define forev(i,n) for(int i=n-1;i>=0;i--)

using namespace std;

int merge(vector<int> & v, vector<int> & temp, int start, int end) {
    
    int i = start,k=start,mid = (start+end) / 2;
    int j = mid + 1;

    int inv_count = 0;

    while (i <= mid && j <= end) {
        if (v[i] <= v[j])
            temp[k++] = v[i++];
        else {
            temp[k++] = v[j++];
            inv_count += (mid - i + 1);
        }
    }

    while (i <= mid)temp[k++] = v[i++];
    while (j <= end)temp[k++] = v[j++];

    i = start, j = end;
    while (i < j) {
        v[i] = temp[i];
        i++;
    }

    return inv_count;
}

int mergeSort(vector<int> &v, vector<int> &temp, int start, int end) {

    int i = start, j = end;
    int inv_count = 0;

    if (i < j) {
        int mid = (i + j) / 2;
        inv_count += mergeSort(v, temp, start, mid);
        inv_count += mergeSort(v, temp, mid+1, end);

        inv_count += merge(v, temp, start, end);
    }

    return inv_count;
}


int countInversions(vector<int> & v) {
    int start = 0, end = v.size() - 1;
    vector<int> temp(v.size());
    return mergeSort(v, temp, start, end);

}

int main()
{
    vector<int> v = { 1,20,6,4,5 };
    int ans = countInversions(v);
    cout << ans << '\n';
    return 0;
}
