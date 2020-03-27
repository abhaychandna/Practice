#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isSubsetSum(int set[], int n, int sum)
{
	vector<vector<bool>> v(n + 1,vector<bool>(sum+1,false));

	for (int i = 0; i < n + 1; i++)
		v[i][0] = true;

	for (int j = 0; j < sum + 1; j++)
		v[0][j] = false;

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < sum + 1; j++)
		{			
			if (set[i - 1] <= j)
			{
				v[i][j] = v[i - 1][j - set[i - 1]] || v[i - 1][j];
			}
			else
				v[i][j] = v[i - 1][j];

		}
	}

	return v[n][sum];
}

int main()
{
	int set[] = { 3, 34, 4, 12, 5, 2 };
	int sum = 9;
	int n = sizeof(set) / sizeof(set[0]);
	if (isSubsetSum(set, n, sum) == true)
		cout<<"Found";
	else
		cout<<"Not Found";
	return 0;
}
