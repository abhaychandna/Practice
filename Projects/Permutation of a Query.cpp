#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ans2
{
	int sum2;
	int sum;
	int n;
	/*_int8 a;
	_int8 b;
	_int8 c;
	_int8 d;*/
};

bool com(ans2 x, ans2 y)
{
	if (x.sum != y.sum && x.sum2 != y.sum2)            // not wking for 11 9 5 10
		return x.sum > y.sum;
	/*else
	{
		tempx = (y.a - x.a) + 
		return x.sum2 < y.sum2;		// WHAT IF WHEN ALL ARE QEUAL
	}*/
}

int main()
{
	// starting form 0 0 0 0 
	{


		int q;
		cin >> q;

		ans2 y[10010]; // INCREASE SIZE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

		for (int i = 0; i < q; i++)
		{
			long long int a, b, c, d;
			cin >> a >> b >> c >> d;
			
			int sum = (a - b) + (b - c) + (c - d);
			int sum2 = a + b + c + d;
			y[i].n = i + 1;
			/*y[i].a = a;
			y[i].b = b;
			y[i].c = c;
			y[i].d = d;*/

			y[i].sum = sum;
			y[i].sum2 = sum2;

		}

		sort(y, y + q, com); // or y+q+1??

		for (int i = 0; i < q; i++)
		{
			//if (y[i].n != 0)
			cout << y[i].n << " ";
		}



	}
}