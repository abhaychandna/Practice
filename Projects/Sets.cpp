#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {

	int n;
	cin >> n;
	set<int>s;
	for (int i = 0; i < n; i++)
	{
		int k, p;
		cin >> p;
		cin >> k;
		if (p == 1)
			s.insert(k);
		else if (p == 2)
		{
			s.erase(k);
		}

		else
		{
			set<int>::iterator itr = s.find(k);
			if (itr == s.end())
				cout << "No";
			else
				cout << "Yes";
		}
	}

	return 0;
}



