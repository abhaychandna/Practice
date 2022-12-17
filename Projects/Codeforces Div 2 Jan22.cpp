#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<cmath>

#define ll long long 
#define mod 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

#define vl vector<long long int>
#define vvl vector<vector<long long int>>
#define pl pair<long long int, long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define forev(i,n) for(int i=n-1;i>=0;i--)

using namespace std;

void print(vvl & a) {
	fo(i, a.size()) {
		fo(j, a[0].size()) {
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}
}

void op1(int i, int j, vvl& a, vvl &v) {
	a[i][0] = a[i - 2][0] xor a[i - 1][1] xor v[i - 1][0];
}
void op2(int i, int j, vvl& a, vvl& v) {
	a[i][j] = a[i - 1][j - 1] xor a[i - 1][j + 1] xor a[i - 2][j] xor v[i - 1][j];
}
ll Ynot()
{
	ll ans = 0;
	ll n;
	cin >> n;
	vvl v(n, vl(n));
	vvl a(n, vl(n,-1));

	fo(i, n)fo(j, n)cin >> v[i][j];

	a[1][0] = 0;
	a[0][1] = v[0][0];

	for (int i = 2; i < n; i++) {
		a[i][i - 1] = 0;
		a[i - 1][i] = a[i - 1][i - 2] xor a[i - 2][i - 1] xor v[i-1][i-1];
	}
	for (int i = 3; i < n; i++) {
		int offset = 0;
		if ( (i+1) % 2) {


			a[i][0] = a[i - 2][0] xor a[i - 1][1] xor v[i - 1][0];
			a[0][i] = a[0][i-2] xor a[1][i-1] xor v[0][i-1];

			op1(i,0,a,v);
			op1(0,i, a, v); 
			offset = 1;
		}
		for (int j = 1+offset; j < i; j += 2) {


			a[i][j] = a[i - 1][j - 1] xor a[i - 1][j + 1] xor a[i - 2][j] xor v[i - 1][j];
			a[j][i] = a[j - 1][i - 1] xor a[j+1][i-1] xor a[j][i-2] xor v[j][i-1];

			op2(i, j, a, v);
			op2(n - i, n - j, a, v);
		}
	}

	a[1][n-1] = 0;
	a[0][n-1-1] = v[0][n-1];

	for (int i = 2; i < n; i++) {
		a[i][n-1-i - 1] = 0;
		a[i - 1][n-1-i] = a[i - 1][n - 1 - i - 2] xor a[i - 2][n - 1 - i - 1] xor v[i - 1][n - 1 - i - 1];
	}
	for (int i = 3; i < n; i++) {
		int offset = 0;
		if ((i + 1) % 2) {
			a[i][n-1] = a[i - 2][n-1] xor a[i - 1][n-1-1] xor v[i - 1][n-i];
			op1(i, a, v);
			op1(n - i, a, v);
			offset = 1;
		}
		for (int j = 1 + offset; j < i; j += 2) {
			op2(i, j, a, v);
			op2(n - i, n - j, a, v);
		}
	}


	print(a);
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
		ans = Ynot();
		//cout << ans << '\n';
	}
}