#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void DFS(vector<vector<int>> adj, int n,vector<int> &distance,string s[],int k)
{
	vector<bool> visited(n+1, false);
	//visited[0] = true;

	queue<int> q;

	distance[1] = 0;
	q.push(1);

	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		if (visited[u] == true)
			continue;
	
		for (int i = u+1; i <= n && i<=u+k; i++)
		{
			if (visited[i] == false && distance[i] > distance[u] + 1 && s[u][i-1] == '1')
			{
				q.push(i);
				distance[i] = distance[u] + 1;
			}
		}

		for (int i = u; i >= 1 && i >= u - k; i--)
		{
			if (visited[i] == false && distance[i] > distance[u] + 1 && s[u][i - 1] == '1')
			{
				q.push(i);
				distance[i] = distance[u] + 1;
			}
		}

		visited[u] = true;
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;

		vector<vector<int>> adj(n+1);
		vector<int> distance(n+1, INT_MAX);
		string s[1001];
		
		for (int i = 1; i <= n; i++)
			cin >> s[i];

		DFS(adj, n,distance,s,k);

		if (distance[n] == INT_MAX)
			cout << "-1" << endl;
		else
			cout << distance[n] << endl;
	}

	
}