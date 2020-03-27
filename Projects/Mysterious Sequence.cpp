#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{

	int pow[31];
	pow[0] = 1;
	for (int i = 1; i < 31; i++)
	{
		pow[i] = pow[i - 1] * 2;
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		cin >> v[0];
		int flag = 0;
		for (int i = 1; i < n; i++)
		{
			cin >> v[i];
			if(v[i]<v[i-1])
			{
				cout << "0"<<endl;
				flag = 1;
				
			}
		}
		
		long long int mod = 1e9 + 7;
		if (flag)
			cout << "0" << endl;
		else
		{
			long long int ans = 1;
			for (int i = 0; i < n - 1 && !flag; i++)
			{
				int both1 = 0;
				int b = 1;
				while (v[i + 1] >= b)
				{
					int bit1, bit2;
					bit1 = v[i] & b;
					bit2 = v[i + 1] & b;

					if (!bit2)
					{
						if (bit1)
						{
							cout << "0" << endl;
							flag = 1;
							break;
						}
					}
					else
					{
						if (bit1)
						{
							both1++;
						}
					}
					b = b << 1;
				}
			
				if (!flag)
				{
					both1 = pow[both1];
					ans = (ans  * both1) % mod;
				}

			}
			if (!flag)
			{
				cout << ans << endl;
			}
		}
	}
}