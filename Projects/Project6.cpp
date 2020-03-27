#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int p;
	scanf("%d", &p);
	int t;
	cin >> t;
	while (t--)
	{
		long long int n, k;
		cin >> n >> k;
		long long int j = 1;
		long long int count = 0;
		while (k > 0)
		{
			k -= j;
			count++;
			j++;
		}
		//cout << count << " " <<k << " "<< j;
		long long int b1 = (n - 1) - count;
		long long int b2 = (b1 - k) + 1;
		for (long long int i = 0; i < n; i++)
		{
			if (i == b1 || i == b2)
				cout << "b";
			else
				cout << "a";
		}
		cout << endl;
	}
}