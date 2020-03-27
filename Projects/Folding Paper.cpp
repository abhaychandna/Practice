
//Incomplete

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long int n, m, w, h,min = INT_MAX;
		cin >> n >> m >> w >> h;
		string s;
		cin >> s;
		vector<int> x, y;
		for (int i = 0; i < m; i++)
		{
			cin >> x[i] >> y[i];
			if (min > y[i])
			{
				min = y[i];
			}
		}
	}
}