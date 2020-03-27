#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int r, n;
		cin >> r >> n;
		vector<int> a(r),p(150,0);

		for (int i = 0; i < r; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			x--;
			p[x]++;
		}

		//sort(p.begin(), p.end());
		int flag = 0;
		int min = a[r-1];
		int index = r-1;

		for (int i = r-2; i >=0; i--)
		{
			if (a[i] > a[i+1])
			{
				if (p[i] == 0)
				{
					flag = 1;
					break;
				}
				else
				{
					if (a[i] > min && i+1 != index)
					{
						flag = 1;
						break;
					}
				}
			}
			else
			{
				min = a[i];
				index = i;
			}
		}

		if (flag == 0)
			cout << "YES";
		else
			cout << "NO";

		cout << endl;
	}
}