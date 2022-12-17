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
#define vvi vector<vector<int>> 
#define vvl vector<vector<long long int>>
#define pi pair<int,int>
#define pl pair<long long int, long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define fon(i,start,end) for(int i=start;i<end;i++)
#define fos(i,start,end,step) for(int i=start;i<end;i+=step)

using namespace std;

ll solve()
{
	ll ans = 0;
	ll n;
	cin >> n;
	vi v(n);
	int mn = 0,f=0;
	vvi arr;
	vi x(4);

	fo(i, n) {
		cin >> v[i];
		if (v[mn] > v[i])mn = i;
	}
	int prime = 1e9 + 7;
	bool last = false;
	fo(i, n-1) {
		if (v[i + 1] >= v[i]) {
			x[0] = i + 1, x[1] = i + 2,x[2] = v[i],x[3]=prime;
			v[i + 1] = prime; 
		}
		else{
			if (v[i]!=prime) {
				x[0] = i + 1, x[1] = i + 2, x[2] = v[i+1], x[3] = prime;
				v[i] = v[i + 1];
				v[i + 1] = prime;
				last = true;
			}
			else {
				continue;
			}
		}
		arr.pb(x);
	}
	cout << arr.size() << '\n';
	fo(i, arr.size()) {
		fo(j, arr[i].size())
			cout << arr[i][j] << " ";
		cout << '\n';
	}
	/*
	ans = n - 1;
	if (mn != 0) {
		ans++, f = true;
		cout << ans << '\n';
		cout << "1 " << mn + 1 << " " << v[mn] << " " << v[0] << '\n';
		swap(v[mn], v[0]);
		
	}
	mn = v[0];
	if(!f)cout << ans << '\n';
	fo(i, n-1) {
		cout << i + 1 << " " << i + 2 << " " << mn+i<<" "<<mn+i+1<<'\n';
	}
	*/
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
		ll ans = 0;
		ans = solve();
		//cout << ans << '\n';
	}
}