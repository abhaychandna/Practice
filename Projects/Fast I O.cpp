#include<iostream>
using namespace std;
#define gc getchar


int main()
{
	int n, k;
	n = read_int();
	k = read_int();
	int nas = 0;
	while (n--)
	{
		int a = read_int();
		if (a % k == 0)
			nas++;
	}
	cout << nas << endl;
}

int read_int() {
	char c = gc();
	while (c < '0' || c>'9') c = gc();
	int ret = 0;
	while (c >= '0' && c <= '9') {
		ret = 10 * ret + c - 48;
		c = gc();
	}
	return ret;
}