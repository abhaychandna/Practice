#include<iostream>
#include<bitset>
using namespace std;
int main()
{
	int n = 5;
	int a[] = { 15,13,11,28,16};
	int sum = 0;
	long long int x = n * pow(2,32);
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	x = x - sum;
	int p = 3;
	sum = sum xor p;
	x = x xor p;
	
	cout <<bitset<32>(sum) << endl << bitset<32>(x);
}	