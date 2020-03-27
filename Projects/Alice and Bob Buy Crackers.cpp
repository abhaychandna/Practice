#include<iostream>
#include<vector>
#include<map>
using namespace std; // 4 1 2 2 1 
int main()
{
	int n;
	cin >> n;
	vector<int> v;
	map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	long long int t = 1 << n;
	long long int sum = 0, ans = 0;
	for (int i = 0; i < t; i++)
	{
		sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (i & (1<<j))		// v[i]
			{
				sum += v[j];
			}
		}
		if(sum>0 && sum%2==0)
			m[sum]++;
	}

	cout << m.size() << endl;
}