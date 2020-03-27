#include<iostream>
#include<vector>

using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--) // invert row nad ocls!!
	{
		int r, c;
		cin >> c >> r;
		int p = 0;
		vector<pair<int, int>> v;
		if (r != c)
		{
			r = (r + c) / 2;
			c = r;
			p = 2;
			v.push_back(make_pair(r, c));
			v.push_back(make_pair(1, 1));
		}
		else if (r != 1)
		{
			//if (r != 1)
			p = 1;
			v.push_back(make_pair(1, 1));
		}
		else
		{
			//v.push_back(make_pair(1, 1));
			//p = 1;
		}int moves = 0;
		
		int left = 0, right = 0;
		bool flag1 = true, flag2 = true;
		for (int i = 7,j=2; i >= 1; i--,j++)
		{
			
				v.push_back(make_pair((9-i), j));
				moves++;
				if (flag1)
				{
					left = i - (j - 1), right = j + (8 - i);
					if (left < 1 && flag1)
					{
						left = 2;
						flag1 = false;
					}
					if (right > 8)
					{
						right = 7;
						flag2 = false;
					}
				}
				else
				{
					left += 2;
					right -= 2;
				}
				
				if (moves < 13)
				{
					v.push_back(make_pair(9 - left, 1));
					moves++;
					v.push_back(make_pair(1, right));
					moves++;
				}	
				
				else
				{
					v.push_back(make_pair(8,left));
					moves++;
					v.push_back(make_pair(9-right, 8));
					moves++;
				}
				v.push_back(make_pair(9 - i, j));
				moves++;
			
		}
		for (int i = 0; i < 3; i++)
		{
			v.pop_back(),moves--;
		}moves += p;
		cout << moves << endl;
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i].first << " " << v[i].second << endl;
		}
	}
}