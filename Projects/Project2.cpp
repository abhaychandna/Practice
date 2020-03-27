#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		int n = s.length();
		int max = 1;
		int temp = 1;
		for (int i = 1; i < n; i++)
		{
			if (s[i] == s[i - 1] + 1)
			{
				temp++;
				continue;
			}
			temp = 1;
			if (max < temp)
			{
				max = temp;
			}
		}
		cout << max << endl;
	}
}