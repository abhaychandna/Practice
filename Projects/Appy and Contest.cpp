#include<iostream>
using namespace std;
long long int gcd(long long int a, long long int b)
{
	if (a == 0)
		return b;
	else
		return gcd(b % a, a);
}
long long int lcm(long long a, long long b)
{
	return (a / gcd(a, b)) * b;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long int a, n, b, k,x,y,z;
		cin >> n >> a >> b >> k;
		
		long long int ans = 0;
		
		

		ans += (n / a);
		ans += (n / b);
		ans -= (2 * (n / lcm(a,b)));
		
		if (ans < k)
			cout << "Lose\n";
		else
			cout << "Win\n";
	}
}