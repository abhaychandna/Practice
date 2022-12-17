#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>

#define ll long long 
#define mod 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

#define vi vector<int>
#define vl vector<long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define fos(i,start,end,step) for(int i=start;i<end;i+=step)

using namespace std;

ll solve()
{
	ll ans = 0;
	ll n, d, m;
	cin >> n >> d >> m;
	vl a(n);
	ll totalsum = 0;
	fo(i, n) {
		cin >> a[i]; totalsum += a[i];
	}
	sort(a.begin(), a.end());
	ll id;
	for (id = 0; id < n; id++)
	{
		if (a[id] > m)
			break;
	}
	ll tempd = d + 1;
	ll x = (n / tempd); ll last = n % tempd;
	vl v;
	ll cnt = 0, sum = 0;
	ll endid = n - 1;
	if (endid < id)
	{
		return totalsum;
	}
	ans = 0;
	ll totalElem = 0;
	int j;
	bool b = false;
	for (j = id - 1; j >= 0 && totalElem < n; j--)
	{
		if ((n - totalElem) < tempd)
		{
			b = true;
			break;
		}
		sum += a[j];

		cnt++;
		if (cnt >= tempd)
		{
			if (sum > a[endid])
			{
				totalElem += cnt;
				//endid--;
				ans += sum;
			}
			else
			{
				while (a[endid] >= sum && totalElem < n)
				{
					totalElem += cnt;
					ans += a[endid];
					endid--;
					if (endid < id)
						break;
				}
				if (endid < id)
					break;
			}


			sum = 0;
			cnt = 0;
		}

	}

	if (b)
	{
		if (endid >= id)
		{
			ll p = a[endid];
			ll tempsum = 0;
			cnt = 0;
			for (; j >= 0 && totalElem < n; j--)
			{
				tempsum += a[j];
				totalElem++;
			}
			if (tempsum >= p)
				ans += tempsum;
			else
				ans += p;
		}
	}
	else if (totalElem < n)
	{
		if (j == -1)
		{
			for (; totalElem < n && endid >= id;)
			{

				ans += a[endid];
				endid--;
				totalElem += endid;

			}
		}
		else if (endid < id)
		{
			j += tempd;
			j--;
			while (totalElem < n)
			{
				ans += a[j];
				j--;
				totalElem++;
			}
		}
	}
	/*else
	{
		for (; totalElem < n && endid >= id;)
		{
			if (a[endid] <= sum)
			{
				totalElem += cnt;
				endid--;
				ans += sum;
			}
			else
			{
				ans += a[endid];
				endid--;
				totalElem += tempd;
			}
		}

	}*/
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	//cin >> t;
	while (t--)
	{
		ll ans = 0;
		ans = solve();
		cout << ans << '\n';
	}
}