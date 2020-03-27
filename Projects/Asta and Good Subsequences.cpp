#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;

		vector<int> v(27, 0);
		int n = s.length();
		int max = 0;
		map<int, int> m;

		for (int i = 0; i < n; i++)
		{
			int k = s[i] - 97;
			int a = k - 1;
			a += 26;
			a %= 26;
			m[k] = m[a] + 1;
		}

		for (int i = 0; i < 27; i++)
		{
			if (max < m[i])
				max = m[i];
		}	

		cout << max << endl;



	}
}