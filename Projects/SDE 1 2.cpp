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


pair<int, int> repeatMissingNumber(vector<int> v) {

    int n = v.size();
    int missing, repeat;
    for (int i = 0; i < n; i++) {
        int id = v[i] - 1;
        if (v[id] < 0) {
            repeat = v[i];
            continue;
        }
        v[id] *= -1;
    }

    for (int i = 0; i < n; i++)
        if (v[i] > 0)missing = v[i];

    return { missing,repeat };
}



int main()
{

    return 0;
}
