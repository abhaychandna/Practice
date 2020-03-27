#include<iostream>
#include<vector>
#include<algorithm>

#include<cmath>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long int a, b, c;
		cin >> a >> b >> c;

		long long int x = a % c,y = b%c,ans = 0;
		ans = (x + y)/c;

		
		if (ans == 1)
		{
			if(x>=y)
			{
				int share = c - x;
				ans = (a / c) + (b / c); 
				ans++;
				cout << ans << endl << share << endl;

			}
			else
			{
				int share = c - y;
				ans = (a / c) + (b / c);
				ans++;
				cout << ans << endl << share << endl;
			}
			 

		}
		else
		{
			ans = (a / c) + (b / c);
			cout << ans << endl << "0" << endl;
		}
		//ans = (a + b) - ans;
		//ans = (a + b) / c;
		//cout << ans << endl;
	}
}