//Incompletet Hackerrank

#include<iostream>
#include<vector>

using namespace std;

int main()
{

	long long int n, q;
	cin >> n >> q;

	vector<vector<long long int>> v(n);
	int l = 0;

	while (q--)
	{
		long long int a, x, y;
		cin >> a >> x >> y;
		if (a == 1)
		{
			long long int seq = ((x ^ l) % n);
			v[seq].push_back(y);
		}
		else
		{
			long long int seq = ((x ^ l) % n);
			l = v[seq][y % v[seq].size()];
			cout << l << endl;
		}
	}

	return 0;
}