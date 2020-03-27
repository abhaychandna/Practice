#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	vector<int> ans(arr.size());
	adjacent_difference(arr.begin(), arr.end(), ans.begin());

	cout << *min_element(ans.begin()+1, ans.end());

}