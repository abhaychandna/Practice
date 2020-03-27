#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; //33
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long int n, p;
		cin >> n >> p;

		vector<int> d(n);
		int id = -1,flag = 0;
		long long int x=0;
		long long int ch = -1, cl = -1;
		for (int i = 0; i < n; i++)
		{
			cin >> d[i];

			if ( p%d[i] != 0) // conditon check agaim?
				id = i;
		}

		if (id == -1)
		{
			sort(d.begin(), d.end());

			for (int i = 0; i < n-1; i++)
			{
				if (d[i + 1] % d[i] != 0) // need to take d[i+1]
				{
					x = (p / d[i + 1]) - 1; // what if this is one?
					ch = x;

					x = d[i + 1] / d[i];
					x = x + 1;
					cl = x;

					id = i;
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				cout << "YES ";
				for (int i = 0; i < n; i++)
				{
					if (i == id)
					{
						cout << cl << " ";
						cout << ch << " ";
						i++;
					}
					else
						cout << "0 ";
				}
				cout << endl;
			}
			else
				cout << "NO";

		}
		else
		{
			cout << "YES ";
			x =(p / d[id]) + 1;
			for (int i = 0; i < n; i++)
			{
				if (i == id)
					cout << x << " ";
				else
					cout << "0 ";
			}		
			cout << endl;
		}
	}
}