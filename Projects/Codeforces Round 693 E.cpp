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

struct man {
	int id;
	int h;
	int w;
};


bool comp(man a, man b) {
	if (a.h > b.h)return true;
	return false;
}

ll solve()
{
	//ll ans = 0;
	int n;
	cin >> n;
	vector<man> v(n);
	for (int i = 0; i < n; i++) {
		man it;
		it.id = i;
		cin >> it.h >> it.w;
		v[i] = it;
	}

	sort(v.rbegin(), v.rend(), comp);
	vector<int> ans(n,-1);
	int mxid = n-1;
	for (int i = n-2; i >= 0; i--) {
		if (v[i].h < v[mxid].w && v[i].w < v[mxid].h)
			ans[mxid]++;
		if (v[i].w > v[mxid].w)
			mxid = i;
	}
	
	for (int i = 0; i < n; i++) {
		cout << ( (ans[i] == -1) ? -1 : (ans[i] + 1) ) << " ";
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