#include<iostream>
#include<vector>
#include<stack>
using namespace std;



int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n + 1);
	int x, y;
	int start;
	cin >> start >> y;
	g[start].push_back(y);
	g[y].push_back(start);

	for (int i = 1; i < m; i++)
	{
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	vector<bool> vis(n + 1, false);
	int count = 0;
	stack<int> s;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == false)
		{
			s.push(i);
			vis[i] = true;
			while (!s.empty())
			{
				int node = s.top();
				s.pop();

				for (int j = 0; j < g[node].size(); j++)
				{
					if (vis[g[node][j]] == false)
					{
						s.push(g[node][j]);
						vis[g[node][j]] = true;
					}
				}

			}
			count++;
		}


		/*if (vis[i] == false)
		{
			dfs(g, vis, i);
			count++;
		}*/

	}

	cout << count;
	//for(int i)

}