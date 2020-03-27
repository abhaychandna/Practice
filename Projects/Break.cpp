#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	int t, s;
	cin >> t >> s;
	if (s == 1)
	{
		while (t--)
		{
			int n;
			cin >> n;
			vector<int> a(n), b(n);
			map<int, int> ma, mb;
			int aMax = -1, bMAx = -1, aMin = 1e9 + 10, bMin = 1e9 + 10;
			for (int i = 0; i < n; i++)
			{
				cin >> a[i];
				ma[a[i]]++;
				if (a[i] > aMax)
					aMax = a[i];
			}
			for (int i = 0; i < n; i++)
			{
				cin >> b[i];
				mb[b[i]]++;
				if (b[i] > bMAx)
					bMAx = b[i];
			}

			aMin = (*ma.begin()).first;
			bMin = (*mb.begin()).first;
			int uniq = ma.size();
			int flag = 0;
			int c = 0, ca = 0;

			if (aMax >= bMAx || aMin >= bMin)
				flag = 1;
			else
			{
				c = (*mb.begin()).second;
				for (auto i = ma.begin(), j = mb.begin(); i != ma.end() && flag == 0; i++)
				{
					ca = (*i).second;
					//c = (*j).second; 
					while (ca > 0)
					{

						if ((*j).first > (*i).first)
						{
							if (i != ma.begin())
							{
								if (mb[(*i).first] == 0)
								{
									if ((*i).second == 1 || ((*i).second > 1 && ca == (*i).second))
									{
										flag = 1;
										break;
									}
								}
							}
							c--;
						}
						else
						{
							flag = 1;
							break;
						}
						if (c == 0)
						{
							j++;
							if (j != mb.end())
								c = (*j).second;
						}
						ca--;
					}
				}
			}


			if (flag == 0)
			{
				cout << "YES";
			}
			else
			{
				cout << "NO";
			}

			cout << endl;
		}
	}
	else
	{
		while (t--)
		{
			int n;
			cin >> n;
			vector<int> a(n), b(n);
			int aMax = -1, bMax = -1, aMin = 1e9 + 10, bMin = 1e9 + 10;
			map<int, int> ma, mb;

			for (int i = 0; i < n; i++)
			{
				cin >> a[i];
				ma[a[i]]++;
				if (a[i] > aMax)
					aMax = a[i];
			}
			for (int i = 0; i < n; i++)
			{
				cin >> b[i];
				mb[b[i]]++;
				if (b[i] > bMax)
					bMax = b[i];
			}

			aMin = (*ma.begin()).first;
			bMin = (*mb.begin()).first;
			int uniq = ma.size();
			int g = max(aMax, bMax), l = min(aMin, bMin);
			int cg = ma[g] + mb[g], cl = ma[l] + mb[l];

			if (bMax <= aMin && uniq == 1)
			{
				cout << "NO";
			}
			else if (cg >= n) // values of n are not uniQUE!!!
			{
				cout << "NO";
			}
			else if (cl >= n)
			{
				cout << "NO";
			}
			else
			{
				cout << "YES";
			}
			cout << endl;
		}
	}
}