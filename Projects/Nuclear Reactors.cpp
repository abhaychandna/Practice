#include <iostream>
#include<vector>
using namespace std;

int main() {
	int an, n, k;
	cin >> an >> n >> k;
	vector<int> a(k);// { 0 };
	for (int i = 0; i < k; i++)
		a[i] = 0;
	int j = 0;
	for (int i = 0; i < an; i++)
	{
		j = 0;
		a[j]++;
		while (a[j] > n)
		{
			a[j] = 0;
			j++;
			if(j<k)
				a[j]++;
		}
		//j=0;
	}
	for (int i = 0; i < k; i++)
		cout << a[i] << " ";


	return 0;
}
