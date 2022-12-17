//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <math.h>
#include <list>
#include <fstream>
#define f first
#define s second
#define pb push_back
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)
#define ff(i,n) for(int i=1;i<=n;i++)
#define IOF ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define N 1000006
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<ll> v(n + 3);

		ff(i, n)
		{
			cin >> v[i];
		}

		ll sum = 0, sub = 0;

		for (int i = 1; i <= n; i++)
		{
			if (v[i] > 0)
				sum += v[i];
			else if (v[i] < 0)
			{
				if (sum > 0)
				{
					int mn = min(sum, abs(v[i]));
					mn = abs(mn);
					sum -= mn;

				}
			}

		}



		/*ll cnt = 0;
		for (int i = n; i >= 1; i--)
		{
			if (v[i] > 0)
				cnt += v[i];
		}*/
		//for (int i = 1; i <= mx; i++)

		cout << sum << "\n";
	}


}



