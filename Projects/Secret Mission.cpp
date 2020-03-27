#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int mxN = 200;
const int mxl = 1e4;
int n, m, l, b[mxl], d1[mxN][mxN], d2[mxN][mxN];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		//vector<int> b;
		//int n, m, l;

		memset(d1, 0x3f, sizeof(d1));

		cin >> n >> m >> l;

		for (int i = 0; i < l; i++)cin >> b[i], --b[i];



		for (int i = 0; i < m; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			u--, v--;
			d1[u][v] = d1[u][v] = w;
		}

		memcpy(d2, d1, sizeof(d1));
		for (int i = 0; i < n; i++)d2[i][i] = 0;

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
				{
					if (d2[i][j] > d2[i][k] + d2[k][j])
						d2[i][j] = d2[i][k] + d2[k][j];
				}

		int ans = 1;
		bool flag = 0;
	}
}
		/*for (int i = 0,j=0; i < l - 1; i = j, ans++)
		{
			int total = b[j];
			while (j < l-1)
			{
				total += b[j + 1];
				if (total > d2[i][j + 1])
				{
					break;
				}
				j++;
			}

			if (i == j)
			{
				flag = 1;
				cout << "-1\n";
				break;
			}
		}

		for (int i = 0, j = 0; i < l - 1; i = j, ++ans) {
			//make sure path from b[i] to b[j] is shortest while trying to extend j
			while (j + 1 < l) {
				//find length of paths between cities in b[i] and b[j+1]
				int e = 0;
				for (int k = i; k + 1 <= j + 1; ++k)
					e += d1[b[k]][b[k + 1]];
				if (e > d2[b[i]][b[j + 1]]) {
					//not shortest path
					break;
				}
				++j;
			}
			if (i == j) {
				//we can't extend
				cout << "-1\n";
				//return;
			}
		}

		if (!flag)
			cout << ans << endl;
	}

}
/*
using namespace std;

const int mxN = 200, mxL = 1e4;
int n, m, l, b[mxL], d1[mxN][mxN], d2[mxN][mxN];

void solve() {
	//input
	cin >> n >> m >> l;
	for (int i = 0; i < l; ++i)
		cin >> b[i], --b[i];
	memset(d1, 0x3f, sizeof(d1));
	for (int u, v, w; m--; ) {
		cin >> u >> v >> w, --u, --v;
		d1[u][v] = d1[v][u] = w;
	}

	//all pairs shortest path with floyd warshall
	memcpy(d2, d1, sizeof(d1));
	for (int i = 0; i < n; ++i)
		d2[i][i] = 0;
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				d2[i][j] = min(d2[i][k] + d2[k][j], d2[i][j]);

	//build a
	int ans = 1;
	for (int i = 0, j = 0; i < l - 1; i = j, ++ans) {
		//make sure path from b[i] to b[j] is shortest while trying to extend j
		while (j + 1 < l) {
			//find length of paths between cities in b[i] and b[j+1]
			int e = 0;
			for (int k = i; k + 1 <= j + 1; ++k)
				e += d1[b[k]][b[k + 1]];
			if (e > d2[b[i]][b[j + 1]]) {
				//not shortest path
				break;
			}
			++j;
		}
		if (i == j) {
			//we can't extend
			cout << "-1\n";
			return;
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
}*/