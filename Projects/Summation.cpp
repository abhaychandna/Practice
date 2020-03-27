#include<iostream>
using namespace std;
typedef long long int ll;

int main()
{
	ll q;
	cin >> q;
	int a[1000001];
	a[1] = 1;
	a[2] = 2;
	int m = 1000000007;
	for (int i = 3; i < 1000001;i++)
	{
		a[i] = (a[i - 1]%m + a[i - 2]%m) % m;
	}
	while (q--) 
	{
		ll n;
		cin >> n;
		cout << a[n]<<'\n';
	}

}