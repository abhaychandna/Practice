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

struct Node {
	ll q, d, p;
	double p_d;
};

bool comp(const Node& a, const Node& b) {
	if (a.p == b.p) {
		return a.d < b.d;
	}
	return a.p > b.p;
	
	
	
	if (a.p_d == b.p_d) {
		if (a.d == b.d) {
			if (a.q == b.q) {
				return a.p > b.p;
			}
			return a.q > b.q;
		}
		return a.d < b.d;
	}
	return a.p_d > b.p_d;
}



it-1 -> it -> it+1
it-1 <- it <- it + 1


	// after erase 

it-1 -> it+1

but it -> it-1 ? why to hcange this 

ll Ynot()
{
	ll ans = 0;
	ll day_mx, n, seed_mx;
	cin >> day_mx >> n >> seed_mx;

	vector<Node> v;
	fo(i, n) {
		Node node;
		double q, d, p;

		cin >> q >> d >> p;
		double p_d = p / d;

		node.q = q;
		node.d = d;
		node.p = p;
		node.p_d = p_d;
		v.pb(node);
	}
	sort(v.begin(), v.end(), comp);
	vl cnt(day_mx + 1, seed_mx);
	set<int> s;
	for (int i = 0; i <= day_mx; i++)s.insert(i);
	for (auto node : v) {
		ll d = day_mx - node.d;

		auto it = s.upper_bound(d);
		it--;

		int i = *it;

		while (i != 0) {
			ll q = min(node.q, cnt[i]);
			cnt[i] -= q;
			node.q -= q;
			ans += q * node.p;
			auto it2 = it;
			it2--;
			//if (cnt[i] == 0)s.erase(std::next(it).base());
			if (cnt[i] == 0)s.erase(it);
			//it2--;
			it = it2;
			if (node.q == 0)break;
			i = *it;
		}

		/*
		for(int i=d;i>0;i--) {
			ll q = min(node.q, cnt[i]);
			cnt[i] -= q;
			node.q -= q;
			ans += q * node.p;
			if (node.q == 0)break;
		}
		*/
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
	for (int i = 1; i <= t; i++) {
		ll ans = Ynot();
		cout << "Case #" << i << ": " << ans << endl;
	}
}