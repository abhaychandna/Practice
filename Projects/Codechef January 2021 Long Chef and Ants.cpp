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

bool comp(pair<int,int> a, pair<int, int> b) {
	if (a.first != b.first)return a.first < b.first;
	return a.second < b.second;
}

void decr(int i, vl &cnt, vector<vl> &v) {
	cnt[i]++;
	cnt[i] = min(cnt[i], (ll)v[i].size());
}

ll solve()
{
	ll ans = 0;
	ll n, m;
	cin >> n;
	vector<vl> v(2 * n);
	int sz = v.size();
	//vector<deque<ll>> vd(sz);
	vl cnt(sz);

	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;



	int x;
	fo(i, n) {
		cin >> m;
		fo(j, m) {
			cin >> x;
			int id = 2*i;
			if (x < 0) {
				x = -x;
				id++;
			}
			v[id].pb(x);
			pair<int, int> p = make_pair(x, id);
			q.push(p);
		}
	}

	while (!q.empty()) {
		bool b = false;
		auto y = q.top();
		q.pop();

		if (!q.empty()) {
			auto z = q.top();
			/*
			int id = z.second;
			int index = lower_bound(v[id].begin(), v[id].end(), q.top().first) - v[id].begin();
			if (index + cnt[y.second] > n - 1) {
				q.pop(); // wrong?
				break;
			}
			*/

			if (y.first == z.first)
				b = true;
		}

		

		if (b) {
			ans += 1;
			while (!q.empty() && q.top().first == y.first) {
				int id = q.top().second;
				
				/*
				int index = lower_bound(v[id].begin(), v[id].end(), q.top().first) - v[id].begin();
				if (index + cnt[y.second] > n - 1) {
					//q.pop(); // wrong?
					break;
				}
				*/

				ans += v[id].size() - 1 - cnt[id];
				decr(id, cnt, v);
				//v[id].pop_back(); // need to remove from queue also;
				q.pop();
			}
			
			ans += v[y.second].size() - 1 - cnt[y.second];
			//cnt[y.second]
			decr(y.second, cnt, v);
			//v[y.second].pop_back();
		}
		else {
			int offset = 1;
			if ((y.second % 2) != 0) offset = -1;

			ans += v[y.second + offset].size() - cnt[y.second + offset]; // -1 maybe??
			decr(y.second, cnt ,v);
			//decr(y.second + 1, cnt, v);
			//v[y.second + 1].pop_back();
		}

	}

	return ans;
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
		cout << ans << '\n';
	}
}