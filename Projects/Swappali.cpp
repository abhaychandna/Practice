#include<iostream>
#include<vector>
//#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		string s;
		cin >> n >> s;
		bool flag = 0;
		bool x = false, y = false;
		int count = 0;
		for (int i = 0,j=n-1; i < n / 2; i++,j--)//less han equal to?
		{
			if (s[i] == s[j])
			{
				x = false;
				y = false;
				continue;
			}
			else if (s[i + 1] == s[j] && !x)
			{
				swap(s[i], s[i + 1]);
				x = true;
				y = false;
				count++;
			}
			else if (s[j - 1] == s[i] && !y)
			{
				swap(s[j], s[j - 1]);
				x = false;
				y = true;
				count++;
			}
			else
			{
				flag = 1;
				break;
			}
		}
		if (n % 2 == 0)
		{
			if (s[n / 2] != s[(n / 2) - 1])
				flag = 1;
		}
		if (!flag)
			cout << "YES\n" << count;
		else
			cout << "NO";
		cout << endl;
	}
}