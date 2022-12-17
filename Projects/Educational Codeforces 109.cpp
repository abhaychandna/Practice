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

#define vi vector<int>
#define vl vector<long long int>
#define vvi vector<vector<int>> 
#define vvl vector<vector<long long int>>
#define pi pair<int,int>
#define pl pair<long long int, long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define fon(i,start,end) for(int i=start;i<end;i++)
#define fos(i,start,end,step) for(int i=start;i<end;i+=step)

using namespace std;

void calc(stack <pair<pair<ll, ll>, ll>> &s, vl &ans, ll m) {

	if (m == 0)
	{
		stack< pair<pair<ll, ll>, ll>> s2;
		while (!s.empty())
		{
			s2.push(s.top());
			s.pop();
		}
		s = s2;
	}
	while (s.size() > 1) {
		auto x = s.top();
		s.pop();
		auto y = s.top();
		s.pop();
		ll sum = (abs(x.first.first - m) + abs(y.first.first - m))/2;
		ans[x.second] = sum;
		ans[y.second] = sum;
	}
	return;
}


ll solve()
{
	// = 0;
	ll n,m;
	cin >> n >> m;
	vl ans(n); 
	vi v(n);
	fo(i, n)cin >> v[i];
	vector<pair<pair<ll,ll>,ll>> k(n);
	fo(i, n) {
		char x;
		cin >> x;
		int p = 0;
		if (x == 'L')p = 1;
		k[i] = { { v[i],p }, i };
	}
	sort(k.begin(), k.end());
	
	stack<pair<pair<ll, ll>, ll>> re, ro, le, lo;

	for (int i = 0; i < n; i++) {
		if (k[i].first.second == 1) {
			if (k[i].first.first % 2) {
				if (!ro.empty()) {
					int x = ro.top().first.first;
					ans[i] = (k[i].first.first - x)/2;
					ans[ro.top().second] = ans[i];
					ro.pop();
				}
				else {
					lo.push(k[i]);
				}
			}
			else {
				if (!re.empty()) {
					int x = re.top().first.first; 
					ans[i] = (k[i].first.first - x) / 2;
					ans[re.top().second] = ans[i];
					re.pop();
				}
				else {
					le.push(k[i]);
				}
			}
		}
		else
		{
			if (k[i].first.first % 2)ro.push(k[i]);
			else re.push(k[i]);
		}
	}

	calc(re, ans, m);
	calc(ro, ans, m);
	calc(le, ans, 0);
	calc(lo, ans, 0);

	if (le.size() > 0 && re.size() > 0) {
		ll time = 0;
		auto x = le.top();
		auto y = re.top();
		time = max((ll)x.first.first, (m - y.first.first));
		ll xf = x.first.first, yf = y.first.first;
		xf -= time;
		xf = -xf;
		yf += time;
		yf = m - (yf - m);
		ll sum = (yf - xf) / 2 + time;
		ans[x.second] = sum;
		ans[y.second] = sum;
		le.pop();
		re.pop();
	}
	
	if (lo.size() > 0 && ro.size() > 0) {
		ll time = 0;
		auto x = lo.top();
		auto y = ro.top();
		time = max((ll)x.first.first, (m - y.first.first));
		ll xf = x.first.first, yf = y.first.first;
		xf -= time;
		xf = -xf;
		yf += time;
		yf = m - (yf - m);
		ll sum = (yf - xf) / 2 + time;
		ans[x.second] = sum;
		ans[y.second] = sum;
		lo.pop();
		ro.pop();
	}

	if (le.size() > 0) {
		auto x = le.top();
		ans[x.second] = -1;
	}
	if (lo.size() > 0) {
		auto x = lo.top();
		ans[x.second] = -1;
	}
	if (re.size() > 0) {
		auto x = re.top();
		ans[x.second] = -1;
	}
	if (ro.size() > 0) {
		auto x = ro.top();
		ans[x.second] = -1;
	}

	fo(i, ans.size())cout << ans[i] << " ";
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
		ll ans = 0;
		ans = solve();
		//cout << ans << '\n';
	}
}