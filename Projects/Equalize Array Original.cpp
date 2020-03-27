#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> a(110);
	int n;
	cin >> n;
	vector<int> arr(n);
	//int max = 0;
	for (int i = 0; i < n; i++)
	{
		a[i] = 0;
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		a[arr[i]]++;
	}

	int max = * max_element(a.begin(),a.end());
	/*int max = 0;
	for (int i = 0; i < a.size();i++)
	{
		if (max < a[i])
			max = a[i];
	}*/
	cout << (arr.size() - max);
}