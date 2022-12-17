#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<fstream>

#define ll long long 
#define mod 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

#define vi vector<int>
#define vl vector<long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define fos(i,n,s,l) for(int i=s;i<n;i+=l)

using namespace std;


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int n;
		cin >> n;
		string inp,oup;
		cin >> inp;
		cin >> oup;
		vi ip(n), op(n);
		fo(j, n)ip[j] = inp[j] == 'Y' ? 1 : 0;
		fo(j, n)op[j] = oup[j] == 'Y' ? 1 : 0;
		string ans = "";
		ans = "Case #";
		ans += to_string(i);
		ans += ":";
		cout << ans << '\n';
		string yes = "Y";
		string no = "N";

		vi farrt(n);
		vector<vector<char>> x(n,vector<char>(n));
		int start = 0,end = 0;
		
		int j = 0, k = 0;
		while (j < n)
		{
			
			x[j][j] = 'Y';
			int g = 0;
			for ( g = j - 1; g >= 0; g--)
			{
				if (op[g + 1] && ip[g])
					x[j][g] = 'Y';
				else
				{
					x[j][g] = 'N';
					g--;
					break;
				}
			}
			while (g >= 0)
			{
				x[j][g] = 'N';
				g--;
			}
			
			for (g = j + 1; g < n; g++)
			{
				if (op[g - 1] && ip[g])
					x[j][g] = 'Y';
				else
				{
					x[j][g] = 'N';
					g++;
					break;
				}
			}
			while (g < n)
			{
				x[j][g] = 'N';
				g++;
			}
			j++;
			
		}


		
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				cout << x[j][k];
			}
			cout << '\n';
		}

	}
}