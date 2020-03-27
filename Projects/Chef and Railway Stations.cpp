#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int mod = 100009; // Method - to only check for elemens present in vector whther they are factor
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> xp,xn,yp,yn;
		map<int, int> xm,ym;
		
		for (int i = 0; i < n; i++)
		{
			int p;
			cin >> p;
			xm[p] = 1;
			if (p >= 0)
				xp.push_back(p);// = 1;
			else
			{
				p = -p;
				xn.push_back(p);// = 1;
			}
		}
		long long int ans = 0;
		for (int i = 0; i < m; i++)
		{
			int p;
			cin >> p;
			ym[p] = 1;
			if (p >= 0)
				yp.push_back(p);// 1;
			else
			{
				p = -p;
				yn.push_back(p);
			}
		}
		int mod2 = 100010;
		mod2 /= 2;
		
		//xtra loop!!!!!!!!!!!!
		int len = xp.size();
		for (int i = 0; i < len; i++)
		{
			long long int temp = xp[i];
			long long int stemp = temp * temp;
			if (temp < mod2)
			{
				for (int k = 1; k <= temp; k++)
				{
					if (stemp % k == 0)
					{
						long long int x = k, y = stemp / k;
						if (ym[k] > 0 && ym[-y] > 0)
							ans++;
						if (ym[-k] > 0 && ym[y] > 0 && k != y)
							ans++;
					}
				}
			}
			else
			{
				for (int k = mod2 * 2; k >= temp; k--)
				{
					if (stemp % k == 0)
					{
						long long int x = k, y = stemp / k;
						if (ym[k] > 0 && ym[-y] > 0)
							ans++;
						if (ym[-k] > 0 && ym[y] > 0 && k != y)
							ans++;
					}
				}
			}
		}

		/*int len = xp.size();
		for (int i = 0; i < len; i++)
		{
			long long int temp = xp[i];
			long long int stemp = temp * temp;
			if (temp < mod2)
			{
				for (int k = 1; k <= temp; k++)
				{
					if (stemp % k == 0)
					{
						long long int x = k, y = stemp / k;
						if (ym[k] > 0 && ym[-y] > 0)
							ans++;
						if (ym[-k] > 0 && ym[y] > 0 && k != y)
							ans++;
					}
				}
			}
			else
			{
				for (int k = mod2 * 2; k >= temp; k--)
				{
					if (stemp % k == 0)
					{
						long long int x = k, y = stemp / k;
						if (ym[k] > 0 && ym[-y] > 0)
							ans++;
						if (ym[-k] > 0 && ym[y] > 0 && k != y)
							ans++;
					}
				}
			}
		}

		len = xn.size();
		for (int i = 0; i < len; i++)
		{
			long long int temp = xn[i];
			long long int stemp = temp * temp;
			if (temp < mod2)
			{
				for (int k = 1; k <= temp; k++)
				{
					if (stemp % k == 0)
					{
						long long int x = k, y = stemp / k;
						if (ym[k] > 0 && ym[-y] > 0)
							ans++;
						if (ym[-k] > 0 && ym[y] > 0 && k != y)
							ans++;
					}
				}
			}
			else
			{
				for (int k = mod2 * 2; k >= temp; k--)
				{
					if (stemp % k == 0)
					{
						long long int x = k, y = stemp / k;
						if (ym[k] > 0 && ym[-y] > 0)
							ans++;
						if (ym[-k] > 0 && ym[y] > 0 && k != y)
							ans++;
					}
				}
			}
		}

		len = yp.size();
		for (int i = 0; i < len; i++)
		{
			long long int temp = yp[i];
			long long int stemp = temp * temp;
			if (temp < mod2)
			{
				for (int k = 1; k <= temp; k++)
				{
					if (stemp % k == 0)
					{
						long long int x = k, y = stemp / k;
						if (xm[k] > 0 && xm[-y] > 0)
							ans++;
						if (xm[-k] > 0 && xm[y] > 0 && k != y)
							ans++;
					}
				}
			}
			else
			{
				for (int k = mod2 * 2; k >= temp; k--)
				{
					if (stemp % k == 0)
					{
						long long int x = k, y = stemp / k;
						if (ym[k] > 0 && ym[-y] > 0)
							ans++;
						if (ym[-k] > 0 && ym[y] > 0 && k != y)
							ans++;
					}
				}
			}
		}

		len = yn.size();
		for (int i = 0; i < len; i++)
		{
			long long int temp = yn[i];
			long long int stemp = temp * temp;
			if (temp < mod2)
			{
				for (int k = 1; k <= temp; k++)
				{
					if (stemp % k == 0)
					{
						long long int x = k, y = stemp / k;
						if (xm[k] > 0 && xm[-y] > 0)
							ans++;
						if (xm[-k] > 0 && xm[y] > 0 && k != y)
							ans++;
					}
				}
			}
			else
			{
				for (int k = mod2 * 2; k >= temp; k--)
				{
					if (stemp % k == 0)
					{
						long long int x = k, y = stemp / k;
						if (ym[k] > 0 && ym[-y] > 0)
							ans++;
						if (ym[-k] > 0 && ym[y] > 0 && k != y)
							ans++;
					}
				}
			}
		}
		*/

		
			if (xm[0] > 0)
			{
				ans += (static_cast<long long int>(yn.size()) + yp.size()) * (static_cast<long long int>(xp.size() - 1) + xn.size());
			}
			if (ym[0] > 0)
			{
				ans += (static_cast<long long int>(yn.size()) + (yp.size()-1)) * (static_cast<long long int>(xp.size()) + xn.size());
			}
		
		cout << ans << endl;
	}
}