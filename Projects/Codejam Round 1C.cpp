#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<cmath>
#include <bitset>


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

string solve()
{
	ll n;
	cin >> n;
	ll N = n;
	string imp = "IMPOSSIBLE";
	vector<string> v(n);
	map<char,int> start, end;
	map<char, vector<string>> ms, me;
	map<char, bool> vis;
	fo(i, n) {
		cin >> v[i];	
	}
	sort(v.begin(), v.end());
	fo(i, n) {
		char s = v[i][0], e = v[i][v[i].size() - 1];
		start[s]++, end[e]++;
		ms[s].push_back(v[i]);
		me[e].push_back(v[i]);
	}
	fo(i, n) {
		char s = v[i][0], e = v[i][v[i].size() - 1];

		int n = v[i].size();
		int j = 0;
		while (j < n && v[i][j] == v[i][0])j++;
		int j2 = v[i].size()-1;
		while (j2 >= 0 && v[i][j2] == v[i][n - 1])j2--;
		if (s == e) {
			if (j <= j2)return imp;
		}
		

		while(j<=j2) {	
			
			if (vis[v[i][j]] == true)return imp;
			{
				char c = v[i][j];

				if (start[c] > 0 || end[c] > 0)return imp;

				vis[v[i][j]] = true;
				while (j <= j2 && v[i][j] == c)j++;
				j--;
			}

			j++;
		}
	}

	int e_f = -1;
	vector<int> nxt(n,-1), pre(n,-1);
	fo(i, n) {
		int n = v[i].size();
		char e = v[i][n - 1];
		for (int j = 0; j < N; j++) {
			if (i==j || pre[i]==j || pre[j] != -1 || v[j][0] != e)continue;
		
			nxt[i] = j;
			pre[j] = i;
			break;
		}

	}


	vector<bool> fv(n);
	string ans = "";
	string last = "";

	{
		string x = v[e_f];
		int nx = e_f;
		while (true) {
			x = v[nx];
			fv[nx] = true;
			reverse(x.begin(), x.end());
			last += x;
			nx = pre[nx];
			if (nx == -1)break;
			
		}
		
	}

	for (int i = 0; i < n; i++) {
		string p = "";
		if (fv[i] == 0) {
			int nx = i;
			while (fv[nx]==0) {
				ans += v[nx];
				fv[nx] = 1;
				if (nxt[nx] == -1)break;
				nx = nxt[nx];
			}
		}
	}
	ans += last;




	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		string ans = solve();
		cout << "Case #" << i << ": " << ans << endl;
	}
}