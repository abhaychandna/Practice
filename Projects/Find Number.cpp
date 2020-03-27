#include<iostream>
using namespace std;
int main()
{
	for (long long int i = 199999999999; i < 100000000000000000; i++)
	{
		int sum = 0;
		long long int temp = i;
		while (temp)
		{
			sum += temp%10;
			temp /= 10;
		}
		if (sum == 100)
			cout << i << endl;
	}
}