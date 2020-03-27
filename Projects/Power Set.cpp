// Power Set.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int l;
	cin >> l;
	vector<int> v;
	for (int i = 0; i < l; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	int size = pow(2,l);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < l; j++)
		{
			if (i & (1 << j))
			{
				cout << v[j];
			}
		}
		cout << endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
