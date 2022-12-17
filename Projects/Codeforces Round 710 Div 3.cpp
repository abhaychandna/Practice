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
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define fos(i,start,end,step) for(int i=start;i<end;i+=step)

using namespace std;

ll solve()
{
	ll ans = 0;
	ll n;
	cin >> n;
	vl v(n);
	map<int, int> mp;
	fo(i, n) {
		cin >> v[i];
		mp[v[i]]++;
	}

	priority_queue<int> pq;

	for (auto itr = mp.begin(); itr != mp.end(); itr++)pq.push((*itr).second);

	while (pq.size() > 2) {
		ll a, b, c;
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		
		a -= b;
		if (a > 0)pq.push(a);
	}

	ll a, b, c;
	a = pq.top();
	pq.pop();
	b = pq.top();
	pq.pop();
	c = pq.top(); pq.pop();
	
	k[0] = a, k[1] = b, k[2] = c;
	if (a >= b + c)return a - b - c;

	ll diff = b - c;
	a -= diff;
	b -= diff;


	if(pq.size()>0)
		ans = pq.top();
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
		ll ans = 0;
		ans = solve();
		cout << ans << '\n';
	}
}