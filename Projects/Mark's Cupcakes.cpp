#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.rbegin(), v.rend());

	long long int ans = 0;

	for (int i = 0; i < n; i++)
	{
		ans = ans + ((long long int) pow(2, i) * v[i]);
	}

	cout << ans;
}