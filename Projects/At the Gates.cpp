#include<iostream>
#include<vector>
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
		int k = 0;
		for (int i = 0; i < n/2; i++) 
		{

			char a = s[i];
			char b = s[n - i - 1];
			if (s[i] != s[n - 1 - i])
			{
				swap(s[i], s[i + 1]);
				k++;
				i++;
			}
		}
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] != s[n - 1 - i])
				flag = 1;
		}
		if (flag == 1)
		{
			cout << "NO";
		}
		else
		{
			cout << "YES\n" << k;
		}
		cout << endl;
	}
}