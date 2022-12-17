#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include <bitset>
#include <cstdint>
#include <initializer_list>
#include <iostream>

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

int sz1 = 1010,sz2 = 1000010;
vi fact1(sz1);
vi cnt(sz2);

vector<vi> adj(sz2);
vi vis(sz2);
vi in(sz2);
void dfs(int node)
{
	vis[node] = true;
	for (int child : adj[node])
	{
		if (!vis[child])
		{
			dfs(child);
		}
		in[child]++;
	}

	return;
}

void sieve()
{

	for (int i = 2; i*i < sz2; i++)
	{
		if (cnt[i] == 0)
		{
			for (int j = i * i; j < sz2; j+=i)
			{
				cnt[j]++;
			}
		}
	}

	ll a = 1;

}

ll solve()
{
	ll ans = 0;
	ll n;
	cin >> n;

	if (n == 1)
		return 0;

	

	return in[n];
	
	ll rn = sqrt(n);
	ans = 1;
	map<int,int> x;
	for (int i = 2; i <= rn; i++)
	{	
		if (n % i == 0)
		{
			
			ll f1 = i, f2 = n / i;

			x[f1]=f1;
			if (f1 != f2)
				x[f2]=f2;

			/*
			ans++;
			ans += cnt[f1];
			if (f1 != f2)
			{
				ans++;
				ans += cnt[f2];
			}
			*/
		}
	}
	sort(x.begin(),x.end());
	
	for (int i = 0; i < x.size(); i++)
	{
		for(int j=)
	}
	

	return ans;
}

int main()
{

	//sieve();


	for (int i = 1; i < sz2; i++)
	{
		for (int j = 2 * i; j < sz2; j += i)
		{
			cnt[j]++;
			//adj[i].pb(j);
		}
	}


	int mx = -1,l=-1;
	for (int i = 1; i < cnt.size(); i++)
	{
		if (cnt[i] > mx)
		{
			mx = cnt[i];
			l = i;
		}
	}

	//dfs(1);

	for (int j = 2; j < sz1; j++)
	{
		for (int i = 2; i < sz1; i++)
		{
			if (i > j && i % j == 0)
				fact1[i]++;
		}
	}



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