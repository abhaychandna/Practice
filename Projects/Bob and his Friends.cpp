#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long int n, a, b, c;
		cin >> n >> a >> b >> c;
		vector<int> f(n);
		
		long long int closeu = INT_MAX,closed = INT_MAX;
		long long int bw = INT_MAX;
		long long int ans = 0,db,da,min=INT_MAX;
		for (int i = 0; i < n; i++)
		{
			cin >> f[i];
			db = abs(f[i] - b);
			da = abs(f[i] - a);

			ans = da + db;

			if (min > ans)
				min = ans;

			/*if (da > db)
			{
				ans = da + db;
			}
			if (f[i] > b)
			{
				ans += (f[i] - a);
			}if (f[i] > a&& f[i] <= b)
			{
				bw = ans;
			}
			if (ans < close)
			{
				ans = close;
			}*/


		}
		min += c;
		cout << min << endl;

	}
}