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


struct CompareTime {
	bool operator()(vector<int> const& p1, vector<int> const& p2)
	{
		// return "true" if "p1" is ordered 
		// before "p2", for example:
		return !(p1[1] < p2[1]);
	}
};


bool comp(vector<int> a, vector<int> b) {
	if(a[0]==b[0])return a[2]<b[2];
	return a[0] < b[0];
}

ll solve()
{
	ll ans = 0;
	ll n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(4));
	map<int, int> mp;
	fo(i, n) {
		ll x, y, z;
		cin >> x >> y >> z;
		v[i][0] = y;
		v[i][1] = y + z;
		v[i][2] = x;
		mp[i + 1] = true;
	}
	sort(v.begin(), v.end(),comp);
	
	ll f;
	cin >> f;

	auto l = v[0];

	priority_queue<vector<int>, vector<vector<int>>,CompareTime> pq;

	vector<int> cnt(n + 1);
	ll start = 0, end = -1;
	fo(i, n) {

		if (!pq.empty())l = pq.top();
		while (!pq.empty() && v[i][0] > pq.top()[1]) {
			auto x = pq.top();
			pq.pop();
			mp[x[3]] = true;
			//cnt[x[3]]--;
		}
		

		auto itr = mp.begin();
		ll platform = (*itr).first;
		v[i][3] = platform;
		cnt[platform]++;
		//mxcnt[platform] = max(mxcnt[platform], cnt[platform]);
		mp.erase(itr);

		pq.push(v[i]);
	}
	
	fo(i, n) {
		if (v[i][2] == f) {
			ans = v[i][3];
			break;
		}
	}
	cout << ans << '\n';
	//sort(mxcnt.rbegin(), mxcnt.rend());
	ll k = *max_element(cnt.begin(),cnt.end());
	
	fo(i, cnt.size()) {
		if (cnt[i] == k)cout << i << '\n';
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	//cin >> t;
	while (t--)
	{
		ll ans;
		ans = solve();
		//cout << ans << '\n';
	}
}