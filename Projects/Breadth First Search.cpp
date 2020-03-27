#include<iostream>
#include<vector>
#include<list>
using namespace std;

void addEdge(vector<vector<int>>& adj, int x, int y)
{
	adj[x].push_back(y);
	//adj[y].push_back(x);
}

void BFS(vector<vector<int>> adj, int s)
{
	vector<bool> visited(adj.size(), false);
	visited[s] = true;

	list<int> queue;

	queue.push_back(s);

	while (!queue.empty())
	{
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		for (auto i = adj[s].begin(); i != adj[s].end(); i++)
		{
			if (visited[*i] == false)
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

int main()
{
	int v = 4;
	vector<vector<int>> adj(v);

	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 1, 2);
	addEdge(adj, 2, 0);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 3);

	int source = 3;

	BFS(adj, source);
}