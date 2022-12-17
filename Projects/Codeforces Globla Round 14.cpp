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
#define vvi vector<vector<int>> 
#define vvl vector<vector<long long int>>
#define pi pair<int,int>
#define pl pair<long long int, long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define fon(i,start,end) for(int i=start;i<end;i++)
#define fos(i,start,end,step) for(int i=start;i<end;i+=step)

using namespace std;


ll solve()
{
	//ll ans = 0;
	ll n, m, gx;
	cin >> n >> m >> gx;
	vector<pair<int, int>> tower(m), v(n);;
	vi ans(n);
	fo(i, n) {
		int x;
		cin >> x;
		v[i] = { x, i };
	}
	sort(v.begin(), v.end());

	priority_queue<pi, vector<pi>, greater<pi> > pq;


	fo(i, m) {
		//pair<int, int> x = make_pair( v[i],i + 1);
		pq.push(make_pair(v[i].first, i + 1));
		ans[i] = i + 1;
	}

	for (int i = m; i < n; i++) {
		auto x = pq.top();
		pq.pop();
		int k = x.first;
		k += v[i].first;
		pq.push({ k,x.second });
		ans[i] = x.second;


		/*
		for (int j = 0; j < m&& i< n; j++) {
			tower[j].first += v[i].first;
			ans[v[i].second] = tower[j].second;
			i++;
		}
		sort(tower.rbegin(), tower.rend());
		*/
	}

	/*
	fo(i, m) {
		if(tower[j])
	}
	*/
	auto x = pq.top().first;
	auto z = x;
	bool p = true;
	while (!pq.empty()) {
		auto y = pq.top();
		x = max(x,y.first);
		z = min(y.first, z);
		pq.pop();
		
	}
	if (z - x > gx)p = false;
	if (p)
	{
		cout << "YES\n";
		fo(i, n) {
			cout << ans[i] << " ";
		}
	}
	else cout << "NO";
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