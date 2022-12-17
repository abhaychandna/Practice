#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>

#define ll long long 
#define mod 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

#define vi vector<int>
#define vl vector<long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define fos(i,start,end,step) for(int i=start;i<end;i+=step)

using namespace std;
int n,half;
vi ans(1001);
bool check(int i, vi & v, vi cnt, vi total,int d)
{
	if (d > half)
		return false;
	if (cnt[0] + total[0] == cnt[1] + total[1])
		return true;
	
	if(i==n)
		return false;

	int x = i % 2;
	if (v[i])
	{
		cnt[x]--;
		total[x]++;
	}
	if (check(i + 1, v, cnt, total,d))
		return true;

	swap(cnt[0], cnt[1]);
	if(v[i])
		total[x]--;
	if(v[i])
		if (check(i + 1, v, cnt, total,d+1))
		{
			ans[i] = 1;
			return true;
		}
	
	return false;
}

ll solve()
{
	cin >> n;
	half = n / 2;
	vi v(n);
	vi cnt(2);
	vi total = cnt;
	fo(i, n)
	{
		ans[i] = 0;
		cin >> v[i];
		if(v[i])
		cnt[(i%2)]++;
	}
	bool k = check(0, v, cnt, total,0);
	int j = 0;
	fo(i, n)
	{
		if (!ans[i])
			j++;
	}
	cout << j << '\n';
	fo(i, n)
	{
		if (!ans[i])
			cout << v[i] << " ";
	}
	cout << '\n';
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--)
	{
		ll ans;
		ans = solve();
		//cout << ans << '\n';
	}
}