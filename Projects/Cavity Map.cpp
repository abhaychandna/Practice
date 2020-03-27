#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	//int a[150][150];
	char ans[110][110];

	int n;
	cin >> n;

	for (int i=0 ;i< n;++i)
	{
		string x;
		cin >> x;
		for (int j = 0; j < n; ++j)
		{
			//string x;
		//	cin >> x;
		//	a[i][j] = static_cast<int>(x[j]);
			ans[i][j] = (x[j]);
		}
	}

	for(int i=1;i<n-1;++i)
		for (int j = 1; j < n-1; ++j)
		{
			if (ans[i + 1][j] < ans[i][j] && ans[i - 1][j] < ans[i][j] && ans[i][j + 1] < ans[i][j] && ans[i][j - 1] < ans[i][j])
				ans[i][j] = 'X';
		}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << ans[i][j];
		}
		cout << endl;
	}
	
}