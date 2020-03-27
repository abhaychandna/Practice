#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int k;
	cin >> k;
	vector<int> all(1000,0);
	vector<int> b(k);
	vector<int> h(1000,0);
	long long int sum = 0, ans = 0, max = 0, total = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> b[i];
		/*if (i == 0)
			all[i] = b[i];
		else
			all[i] += all[i-1] + b[i];
		*/
		if (max < b[i])
			max = b[i];
		h[b[i]]++;
	}
	
	{
		//h[0] = 0;
		total = h[max];
		for (int i = max-1; i > 0; i--)
		{
			h[i] += h[i + 1];
			total += h[i];
		}
	}

	sort(a.begin(), a.end());

	int left = 0;

	if (n > total)
		cout << "-1";
	else
	{
		int i;
		/*for ( i = n - 1; i >= n - k; i--)
		{
			ans += a[i];
		}
		left = n - k - 1;
		while (left >= 0)
		{
			for (int j = 2; left >= 0; j++)
			{
				int p = j;
				while (h[j] > 0 && left>=0)
				{
					ans += (static_cast<long long int>(a[left]) * static_cast<long long int>(j));
					//h[j]--;
					p--;
					left--;
				}
			}
		}*/
		left = n-1;
		for (int j = 1; left >= 0; j++)
		{
			//int p = j;
			while (h[j] > 0 && left >= 0)
			{
				ans += (static_cast<long long int>(a[left])* static_cast<long long int>(j));
				h[j]--;
				//p--;
				left--;
			}
		}

		cout << ans;
	}

}