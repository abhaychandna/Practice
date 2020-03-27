#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> v(401),v2(401); // 2 240 3 639 // 2 240 1 639 // 2 240 3 1039 // 2 240 3 640// 2 2017 2 2019 // 2 240 2 635 // 2 240 2 634 
	int loop = 18 % 4; // check for large tcs // 2 400 2 1199 // 2 2015 2 2815
	int date = 2;
	//long long int ans = 0;
	for (int i = 18; i < 418; i++)
	{
		if (loop == 0 && i % 100 != 0 || i==400) // v[400] is present in v[0] 
		{
			if (date == 0)
			{
				v[i % 400] = 1;
				//cout << i % 400 <<endl;
			}
			date -= 2;
		}
		else
		{
			if (date == 6 || date == 0)
			{
				v[i % 400] = 1;
				//cout << i % 400 << endl;
			}
			date -= 1;
		}

		date = (date + 7) % 7;
		loop = (loop + 1) % 4;
	}
	long long int tsum = 0;
	tsum = v[0];
	for (int i = 1; i < 401; i++)
	{
		v2[i] += tsum;
		tsum += v[i];
	}

	int t;
	cin >> t;
	while (t--)
	{
		long long int ans = 0;
		long long int m1, m2, y1, y2;
		cin >> m1 >> y1 >> m2 >> y2;

		if (m1 > 2) // what if y1+ 1 = y2 -1 ??
			y1++;
		if (m2 < 2)
			y2--;

		if (y1 <= y2)
		{
			long long int dif = (long long)y2 - y1;
			long long int fact = dif / 400;

			if (fact > 0)
			{
				ans += v2[400] * fact;
			}

			dif = dif % 400;
			if (dif > 0)
			{
				dif = y1 + (fact * 400); // what is need for diff??
				long long int x = (y2+1) % 400; // for y1 = y2+1
				
				if (x != y1 % 400) // previous was x!=y1
				{
					for (int i = y1 % 400; i != x;)
					{
						ans += v[i];
						i = (i + 1) % 400;
					}
				}
				else
					ans += 101;
			}
			else
			{
				//if (fact == 0)
				{
					ans += v[y1%400];
				}
			}
			/*if (v[y2 % 400] >= v[(y1 - 1) % 400]) // if y1 & y2 both 400 // greater than or euqla 2 // dounbling 2 times cuz 
			{
				if(y2-(y1-1)<400)
					ans += static_cast<long long int>(v[y2 % 400]) - v[(y1 - 1) % 400]; //what if y2%400 is 0 but y1%400-1 is bigger  // y1 %400 =0?? // v[0] contains value of v[400]
				else
				{
					ans += 101;
				}
			}
			else
			{
				ans += static_cast<long long int>(v[400]) - v[(y1 - 1) % 400];
				ans += static_cast<long long int>(v[y2 % 400]) - v[0];
			}*/
			cout << ans << endl;		
		}
		else
			cout << "0" << endl;
	}
}