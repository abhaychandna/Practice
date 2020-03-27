#include<iostream>
using namespace std;

/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
*/
#include<vector>
#include<algorithm>
int main()
{
    long long int n;
    cin >> n;
    vector<int> a(n), b(n),c(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)cin >> b[i];

    for (int i = 0; i < n; i++)c[i] = a[i] - b[i];
    sort(c.begin(), c.end());
    long long int ans = 0;
    for (int l = 0, r = n - 1; l<r ;)
    {
        if (c[l] + c[r] <= 0)
        {
            ans+= r-l;
            l++;
            continue;
        }
        else
        {
            r--;
            continue;
        }
    }

    ans = (n*(n-1)/2) - ans;
    cout << ans << endl;
    return 0;
}
