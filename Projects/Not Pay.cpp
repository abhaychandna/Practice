#include<iostream>
#include<vector>
using namespace std;
int main()
{
	long long int n, k;
	cin >> n >> k;
	int r = 100009;
	vector<long long int> v(r),v2;
	long long int x =0;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		v2.push_back(x);
		v[x]++;
	}
	long long int max = v2[v2.size() - 1];
	long long int ans = 0;
	long long int temp = -1;
	int flag = 0;
	if (k > 1)
	{
		for (long long int i = 0; i < v2.size(); i++)
		{
			if (v2[i] * k * k <= max)
			{
				//if (v2[i] != temp)
				{
					if (v2[i]!=0)
					{
						if (v[v2[i] * k]>0 && v[v2[i] * k * k]>0)
						{
							ans += v[static_cast<long long int>(v2[i]) * k] * v[static_cast<long long int>(v2[i]) * k * k];
						}
					}
					else
					{
						if (v[0] >= 3 && flag == 0)
						{
							ans += (static_cast<long long int>(v[0])* (v[0] - 1)* (v[0] - 2)) / 6;// may or may not divie by 6 . AHEAD AlSO
							flag = 1;
						}
					}
				}
				//temp = v2[i];
			}
			else
				break;
		}
	}
	else if (k == 1)
	{
		for (long long int i = 0; i < v2.size(); i++)
		{
			if (v2[i] != temp)
			{
				if (v[v2[i]] >= 3)
					ans += (static_cast<long long int>( v[v2[i]]) * (v[v2[i]] - 1) * (v[v2[i]] - 2))/6;// may or may not divide by 6
			}
			temp = v2[i];
		}
	}
	
	
	cout << ans << endl;

}