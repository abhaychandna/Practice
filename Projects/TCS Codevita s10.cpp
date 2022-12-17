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

map<string, vl> mp;
map<ll, ll> price_cnt;
map<string, ll> lot_appointed;
ll Ynot()
{
	ll ans = 0;
	ll lot_cnt = 0;

	ll ipo_sz, lot_sz, upper_lmt, base_price;
	cin >> ipo_sz>> lot_sz>> upper_lmt>> base_price;
	string pan_reqd;
	cin >> pan_reqd;
	ll cnt;
	cin >> cnt;
	while (cnt--) {
		string pan,demat;
		cin >> pan >> demat;
		ll lot, price;
		string p;
		cin >> lot >> p;
		//lot = min(lot, upper_lmt);
		if (mp.find(pan) != mp.end()) {
			continue;
		}
		if (p == "CUTOFF") {
			price = INT_MAX;
		}
		else {
			price = stoi(p);
		}
		price_cnt[price]++;
		lot_cnt += lot;
		lot = min(lot, upper_lmt);
		mp[pan] = {lot, price};
	}

	ll issue_price = base_price;
	if ((lot_cnt * lot_sz) > ipo_sz) {
		cout << "Oversubscribed\n";
		if (price_cnt[base_price + 1] + price_cnt[-1] >= price_cnt[base_price])
			issue_price = base_price + 1;
	}
	else {
		cout << "Undersubscribed\n";
	}
	cout << issue_price << '\n';
	
	ll lot_remaining = (ipo_sz/lot_sz);
	for (auto m : mp) {
		if (lot_remaining <= 0)break;
		auto x = m.second;
		auto pan = m.first;
		if (x[1] >= issue_price) {
			lot_appointed[pan]++;
			lot_remaining--;
		}
	}
	if (lot_appointed[pan_reqd] == 0) {
		cout << 0 << '\n';
		return 1;
	}
	else {
		for (auto m : mp) {
			if (lot_remaining <= 0)break;
			auto x = m.second;
			auto pan = m.first;
			if (x[1] >= issue_price) {
				lot_appointed[pan] += min(lot_remaining, x[0]-1);
				lot_remaining -= (lot_appointed[pan] - 1);
			}
		}
	}
	cout << lot_appointed[pan_reqd] << '\n';
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
		ll ans = 0;
		ans = Ynot();
		//cout << ans << '\n';
	}
}