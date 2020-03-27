#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int m = 1e9 + 7;
	vector<int> v(1e6);
	long long int k = 1e6;
	k -= 1;
	v[1] = 1;
	for (long long int i = 2; i <= k; i++)
	{
		v[i] = (i + ((v[i - 1] % m) % m) + (i * (v[i - 1] % m)) % m) % m;
	}


	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		//if (n = 2800)
			//cout << "" << endl;
		//else
			cout << v[n] << endl;
		
	}
}