#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<vector<int>>& adj, int x, int y)
{
	adj[x].push_back(y);
	adj[y].push_back(x);
}


void DFSmore(vector<vector<int>> adj, int u, vector<bool>& visited)
{
	visited[u] = true;
	cout << u << " ";
	for (int i = 0; i < adj[u].size(); i++)
	{
		if (visited[adj[u][i]] == false)
		{
			DFSmore(adj, adj[u][i], visited);
		}
	}
}

void DFS(vector<vector<int>> adj, int v)
{
	vector<bool> visited(v, false);

	for (int u = 0; u < v; u++)
	{
		if (visited[u] == false)
		{
			DFSmore(adj, u, visited);
		}
	}
}

int main()
{
	int v = 5;
	vector<vector<int>> adj(v);

	addEdge(adj, 0, 1);
	addEdge(adj, 0, 4);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 1, 4);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 4);

	DFS(adj, v);
}