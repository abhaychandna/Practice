#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<fstream>

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

ll solve()
{
	ll ans = 0;
	ll n, k, w;
	cin >> n >> k >> w;
	vector<pair<ll,ll>> l(k);
	vl ltemp(k),htemp(k);
	fo(i, k) {
		cin >> ltemp[i];
	}
	
	ll al, bl, cl, dl;
	cin >> al >> bl >> cl >> dl;
	al %= dl;
	bl %= dl;
	cl %= dl;

	fo(i, htemp.size())cin >> htemp[i];
	
	ll ah, bh, ch, dh;

	cin >> ah >> bh >> ch >> dh;
	ah %= dh;
	bh %= dh;
	ch %= dh;

	for (int i = 0; i < k; i++) {
		l[i] = { ltemp[i],htemp[i] };
	}

	while (k < n)
	{
		ll lsum = 0,hsum = 0;
		lsum = (((l[k - 2].first) % dl) * al) % dl;
		lsum += (((l[k - 1].first) % dl) * bl) % dl;
		lsum %= dl;
		lsum += cl;
		lsum %= dl;
		lsum++;
		
		hsum = (((l[k - 2].second) % dh) * ah) % dh;
		hsum += (((l[k - 1].second) % dh) * bh) % dh;
		hsum %= dh;
		hsum += ch;
		hsum %= dh;
		hsum++;
		
		l.pb({ lsum, hsum });
		k++;

	}

	sort(l.begin(), l.end());
	ans = 0;

	ll peri = 0;
	peri = ((w + (l[0].second)) * 2);
	ans = peri;
	ans %= mod;
	vl prev(4,-1);// prev_wall = { l[0].first + w,l[0].second };
	stack<ll> st;
	st.push(0);
	ll nextHeight = -1;
	nextHeight = -1;
	//cout << peri << " ";
	// 1148
	for (ll i = 1; i < l.size(); i++) {

		// maybe dont mod perimeter? // check width < 20 check line 101  && 119
		if (l[i - 1].first + w < l[i].first) {
			peri = (peri + (((w + l[i].second) * 2) ));

			ans = (ans * (peri % mod)) % mod;
			//cout << peri << " ";
			while (!st.empty())
				st.pop();
			st.push(i);
			nextHeight = -1;
			continue;
		}
		
		//ll diff = l[i].second - l[i - 1].second;
		bool x = true;
		if (!st.empty())
		{
			while (st.empty() == false && l[i].first <= l[st.top()].first + w) {

				if (l[i].second > l[st.top()].second) {
					nextHeight = st.top();
					st.pop();
				}
				else {
					break;
				}

				if (!st.empty() && l[st.top()].first + w < l[i].first) {
					x = false;
					peri += ((l[i].second - l[nextHeight].second) * 2);
					while (!st.empty())
						st.pop();
					st.push(i);
					nextHeight = -1;
					break;
				}
			}
			if (x) {
				if (!st.empty() && l[st.top()].first + w < l[i].first) {
					x = false;
					peri += ((l[i].second - l[nextHeight].second) * 2);
					while (!st.empty())
						st.pop();
					st.push(i);
					nextHeight = -1;
					break;
				}
			}
		}

		if (!st.empty() && x) {
			//if(nextHeight != -1)
				//peri -= l[i].second - nextHeight;
			st.push(i);
			nextHeight = i;
		}
		else if (x) {
			peri += ((l[i].second - l[nextHeight].second)*2);
			st.push(i);
			nextHeight = i;

		}
			
		peri += (l[i].first - l[i - 1].first)*2;
		//
		//peri = (peri - l[i-1].second);// + mod) % mod;
		//peri = peri + l[i].second;
		//peri = peri + abs(l[i-1].second - l[i].second);
		//
		//ll diff = 0;
		//diff = (l[i].first - l[i-1].first)*2;
		//peri = peri + diff;

		//if (prev[0] == -1) {
		//	prev[0] = l[i].first;
		//	prev[1] = max(l[i].second, l[i - 1].second);
		//	prev[2] = i;
		//	prev[3] = i - 1;
		//}

		////prev_wall = { ,l[i].first + w };
		//cout << peri << " ";
		ans = (ans * (peri % mod)) % mod;
	}


	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("A1op.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		ll z = 0;
		//string s;
		//cin >> s;
		char x = '0' + i;
		string ans = "Case #";
		//+x + ': ';
		ans += to_string(i);
		ans += ": ";
		//cout << ans;
		z = solve(); 
		cout << ans<<z<<'\n';
		//cout << ans<<z << '\n';
	}
}