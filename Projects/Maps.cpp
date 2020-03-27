#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	int n;
	cin >> n;
	map<string, int> m;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		if (k == 1)
		{
			string s1;
			int p, old;
			cin >> s1 >> p;
			map<string, int>::iterator itr = m.find(s1);
			if (itr == m.end())
				m.insert(make_pair(s1, p));
			else
			{
				old = m[s1];
				m.erase(s1);
				m.insert(make_pair(s1, p + old));
			}
		}
		else if (k == 2)
		{
			string s1;
			cin >> s1;
			m.erase(s1);
		}
		else
		{
			int f = 0;
			string s1;
			cin >> s1;
			map<string, int>::iterator itr = m.find(s1);
			if (itr != m.end())
				f = m[s1];
			cout << f << "\n";
		}
	}

	return 0;
}



