#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int r, c, m;
		
					cin >> r >> c >> m;

					int ans = 0;
					if (m < 7)
					{
						for (int i = 1; i <= m; i++)
						{
							ans += 8 * i;
						}
						int ri = 0, ri2 = 0, ci2 = 0, ci = 0;
						int t, rt1, rt2, ct1, ct2;
						t = m - (r - 1);
						if (t > 0)
						{
							rt1 = t;
							t = ((2 * m) + 1) * t;
							ri = 1;

							ans -= t;
						}

						t = m - (8 - r);
						if (t > 0)
						{
							rt2 = t;
							t = ((2 * m) + 1) * t;
							ri2 = 1;

							ans -= t;
						}



						t = m - (c - 1);
						if (t > 0)
						{
							ct1 = t;
							t = ((2 * m) + 1) * t;
							ci = 1;

							ans -= t;
						}

						t = m - (8 - c);
						if (t > 0)
						{
							ct2 = t;
							t = ((2 * m) + 1) * t;
							ci2 = 1;

							ans -= t;
						}

						int overlap;
						if (ri && ci)
						{
							overlap = rt1 * ct1;
							ans += overlap;
						}
						if (ri2 && ci2)
						{
							overlap = rt2 * ct2;
							ans += overlap;
						}
						if (ri && ci2)
						{
							overlap = rt1 * ct2;
							ans += overlap;
						}
						if (ri2 && ci)
						{
							overlap = rt2 * ct1;
							ans += overlap;
						}

						ans++;
						cout << ans << endl;

					}
					else
						cout << "64" << endl;

				
	}
}