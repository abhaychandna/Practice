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

bool comp2(vl a, vl b) {
	if (a[1] < b[1])return true;
	return false;
}
bool comp3(vl a, vl b) {
	if (a[2] < b[2])return true;
	return false;
}bool comp4(vl a, vl b) {
	if (a[3] < b[3])return true;
	return false;
}bool comp5(vl a, vl b) {
	if (a[4] < b[4])return true;
	return false;
}

struct pairComp {

public:

	bool operator()(pl a, pl b) {
		if (a.first > b.first)return true;
		return false;
	}
};

int Ynot()
{
	int ans = -1;
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(6));
	fo(i, n)v[i][5] = i;
	fo(i, n)
		fo(j, 5)
			cin >> v[i][j];

	for (int i = 0; i < n; i++) {
		bool flag = true;

		for (int j = 0; j < n; j++) {
			if (i == j)continue;

			int cnt = 0;
			for (int k = 0; k < 5; k++)if (v[j][k] < v[i][k])cnt++;
			if (cnt > 2) {
				flag = false;
				break;
			}
		}
		if (flag) {
			ans = i + 1;
			break;
		}
	}

	return ans;

	/*
	for (int j = 0; j < 5; j++) {
		priority_queue<pl,vector<pl>,pairComp> pq;
		for (int i = 0; i < n; i++) {
			pq.push({ v[i][j], v[i][5] });
		}
		int k = n;
		while (!pq.empty()) {
			auto x = pq.top();
			pq.pop();
			v[x.second][j] = k--;
		}
	}

	priority_queue<pl> pq;
	fo(i, n) {
		ll sum = 0;
		fo(j, 5) {
			sum += v[i][j];
		}
		pq.push({ sum, i });
	}

	ans = -1;
	ll sum = pq.top().first;
	if (sum >= (3 * n)) {
		ans = pq.top().second;
		ans++;
	}

	/*sort(v.begin(), v.end());
	map<int, int> mp;
	mp[v[0][5]]++;
	sort(v.begin(), v.end(),comp2);
	mp[v[0][5]]++;
	sort(v.begin(), v.end(), comp3);
	mp[v[0][5]]++;
	sort(v.begin(), v.end(), comp4);
	mp[v[0][5]]++;
	sort(v.begin(), v.end(), comp5);
	mp[v[0][5]]++;

	ans = -1;
	for (auto x : mp) {
		if (x.second >= 3)ans = x.first;
	}
	*/
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
		int ans = 0;
		ans = Ynot();
		cout << ans << '\n';
	}
}