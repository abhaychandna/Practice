#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		long long int sum=0;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			sum += x;
		}
		cout << (sum % k) << endl;
	}
}