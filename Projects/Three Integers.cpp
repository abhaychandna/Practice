#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int min = 1e9,mina=0,minb=0,minc=0;
		bool flag = false;
		for (int i = 1; i < 2 * a; i++)
		{
			for (int j = i; j < 2 * b; j += i)
			{
				int x = c / j;
				int z = j * (x + 1); 
				x = j * x;
				
				x = abs(c - x) < abs(c - z) ? x : z;
				//x = j * x < j * (x + 1) ? j * x : j * (x + 1); // edge case
				int y = abs(a - i) + abs(b - j) + abs(c - x);
				if (y < min)
				{
					min = y;
					mina = i;
					minb = j;
					minc = x;
					flag = true;
				}
			}
		}

		if (flag)
		{
			cout << min << endl << mina << " " << minb << " " << minc << endl;
		}
	}
}