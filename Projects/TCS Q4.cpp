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

//#define fo(i,n) for(int i=0;i<n;i++)
//#define fos(i,start,end,step) for(int i=start;i<end;i+=step)

using namespace std;

void solve()
{
	//ll ans = 0;
	int m, n;
	cin >> n >> m;
	vector<vi> v(n, vi(m)),vis(n, vi(m)),ans(n, vi(m));
	for (int i = 0; i < n; i++)for (int j = 0; j < m;j++)cin >> v[i][j];
	
	int r = min(n, m) / 2;
	vi rotation;
	for(int i=0;i<r;i++)
	{
		int h;
		cin >> h;
		rotation.pb(h);
	}
	int rs = rotation.size();
	for (int i = 0; i < rs;i++) {

		vi layer;
		{
			int row = i;
			int col = i;

			for (int j = row; j <= n - 1 - row; j++) {
				layer.pb(v[j][col]);
			}
			if (col != m - 1 - i)
			{
				row = n - 1 - i;
				col = m - 1 - i;
				for (int j = i + 1; j <= col; j++)
					layer.pb(v[row][j]);

				if (i != n - 1 - i) {
					row = n - 1 - i;
					col = m - 1 - i;
					for (int j = row - 1; j >= i; j--)
						layer.pb(v[j][col]);
					row = i;
					col = m - 1 - i;
					for (int j = col - 1; j > i; j--)
						layer.pb(v[row][j]);
				}
			}
		}
		

		vi temp(layer.size());
		int ls = layer.size();
		if(i%2==0)
		for(int j=0;j< ls;j++)
			temp[(j + rotation[i]) % ls] = layer[j];
		else
		{
			for (int j = 0; j < ls; j++)
			{
				
				temp[(j - (rotation[i]%ls) + ls) % ls] = layer[j];
			}
		}
		int id = 0;
		
		{
			int row = i;
			int col = i;

			for (int j = row; j <= n - 1 - row; j++) {
				ans[j][col]=temp[id++];
			}
			if (col != m - 1 - i)
			{
				row = n - 1 - i;
				col = m - 1 - i;
				for (int j = i + 1; j <= col; j++)
					ans[row][j]=temp[id++];

				if (i != n - 1 - i) {
					row = n - 1 - i;
					col = m - 1 - i;
					for (int j = row - 1; j >= i; j--)
						ans[j][col]=temp[id++];
					row = i;
					col = m - 1 - i;
					for (int j = col - 1; j > i; j--)
						ans[row][j]=temp[id++];
				}
			}
		}
		
	}

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			cout << ans[i][j] << " ";
		}
		cout << '\n';
	}
	return;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
		//cout << ans << '\n';
	}
}