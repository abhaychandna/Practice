#include<iostream>
#include<vector>  
#include<chrono>
using namespace std;
int main()
{
	//auto start = chrono::high_resolution_clock::now();
	int x = (2 * 1e5);
	vector<bool> l(x + 1, true);
	vector<int> v(31);
	v[0] = 0;
	v[1] = 1;
	for (int i = 2; i < v.size(); i++)
	{
		v[i] = v[i - 1] + v[i - 2];
		if(v[i] < l.size())// erro for high testcases
			l[v[i]] = false;
	}

	int n;
	//cin >> n;
	
	for (int i = 7; i < l.size(); i++)// error for prime + 1 ,fib && fib+1 && 76
	{
		if (l[i] == true)
		{
			for (int j = 3; j < 31; j++)
			{
				if (v[j] + i < l.size())
				{
					l[v[j] + i] = false;
				}
				
			}
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n < 7)
		{
			if (n == 0 || n == 1)
				cout << "Bob";
			else
				cout << "Alice";
		}
		else
		{
			if (l[n] == 1)
				cout << "Bob";
			else
				cout << "Alice";
		}
		cout << endl;

	}
	//auto stop = chrono::high_resolution_clock::now();
	//auto duration = chrono::duration_cast<micro>(stop - start);
	
}