#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <math.h>
#include <list>
#include <fstream>
#define f first
#define s second
#define pb push_back
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)
#define IOF ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define N 1000006
using namespace std;

vector<int> vi[15];
vector<int>  pop(13), inf(13), days(13, 0);
vector<int> v;

bool vis[500000];
void dfs(int source, int dcnt)
{
	v.push_back(source);
	vis[source] = true;
	inf[source] -= min(pop[dcnt], inf[source]);

	if (inf[source] == 0)
		days[source] = dcnt;

	for (auto child : vi[source])
	{
		if (vis[child] == false)
		{
			vis[child] = true;
			dfs(child, dcnt);
		}
	}

	for (int i = 0; i < vi[v[0]].size(); i++)
	{

		vi[v[0]].erase(vi[v[0]].begin() + i);

		for (int j = 0; j < vi[i].size(); j++)
		{
			if (vi[i][j] == v[0])
			{
				vi[i].erase(vi[i].begin() + j);
			}
		}
	}

	v.clear();
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{

		

		int n;
		cin >> n;
		vector<int> randi(n + 1);
		for (int i = 0; i <= n; i++)
		{
			vis[i] = 0;
		}
		for (int i = 1; i <= n + 1; i++)
		{
			vi[i].clear();
			pop[i] = 0;
			inf[i] = 0;
			days[i] = 0;
		}
		for (int i = 1; i <= n - 1; i++)
		{
			int u, v;
			cin >> u >> v;
			vi[u].push_back(v);
			vi[v].push_back(u);
		}

		for (int i = 1; i <= n; i++)
			cin >> randi[i];
		for (int i = 1; i <= n; i++)
		{
			cin >> pop[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> inf[i];
		}
		for (int i = 1; i <= n; i++)
		{
			int s = randi[i];
			int dcnt = i;
			dfs(s, dcnt);

		}

		for (int i = 1; i <= n; i++)
		{
			if (inf[i] != 0)
				cout << "-1 ";
			else
				cout << days[i] << " ";

		}

		cout << "\n";

		pop.clear();
		inf.clear();
		days.clear();
		v.clear();
	}
}
