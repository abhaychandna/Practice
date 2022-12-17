//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <bits/stdc++.h>
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

int main()
{
	int n, m;
	cin >> n >> m;
	int x, y;
	cin >> x >> y;

	int vis[103][103] = { 0,0 };
	for (int i = x; i >= 1; i--)
	{
		if (vis[i][y] == 0)
		{
			cout << i << " " << y << "\n";
			vis[i][y] = 1;
		}
	}

	for (int j = y; j >= 1; j--)
	{
		if (vis[1][j] == 0)
		{
			cout << "1" << " " << j << "\n";
			vis[1][j] = 1;
		}
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (vis[i][j] == 0)
			{
				cout << i << " " << j << "\n";
				vis[i][j] = 1;
			}
		}
	}
}


