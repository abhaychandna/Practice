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
	freopen("outputalc.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int n;
		cin >> n;
		string ans = "";
		ans = "Case #";
		ans += to_string(i);
		ans += ":";
		cout << ans << '\n';
		string yes = "Y", no = "N";
	}
}