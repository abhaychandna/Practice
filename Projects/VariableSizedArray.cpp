#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n, q;
	cin >> n >> q;
	vector<vector<int>> a(n);
	for (int i = 0; i < n; i++)
	{
		int p;
		cin >> p;

		a[i].resize(p);

		for (int j = 0; j < p; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < q; i++)
	{
		int n, m;
		cin >> n >> m;
		cout << a[n][m] << endl;
	}

	return 0;
}

