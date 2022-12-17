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
	string yes = "Yes", no = "No";
	int n; cin >> n;
	vi v(n);
	
	vi cnt(3);

	fo(i, n){
		cin >> v[i];
		cnt[v[i] % 3]++;
	}

	int x = (n / 2) + (n % 2);
	if (cnt[3] > x)
	{
		cout << no;
		return 0;
	}
	else
		cout << yes;
	cout << '\n';

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--)
	{
		string yes = "Yes", no = "No";
		int n; cin >> n;
		vi v(n);

		vi cnt(3);

		fo(i, n) {
			cin >> v[i];
			cnt[v[i] % 3]++;
		}

		int x = (n / 2) + (n % 2);
		if (cnt[0] > x)
		{
			cout << no;
		}
		else
		{
			int x = cnt[0];
			if (cnt[2] > x)
			{
				if (cnt[1] == 0)
					cout << yes;
				else
					cout << no;
			}
			else
				cout << yes;
			
		}cout << '\n';
	}
}