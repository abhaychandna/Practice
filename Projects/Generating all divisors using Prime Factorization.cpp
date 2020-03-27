#include <iostream>
#include<vector>
#include<map>
#define MAX 100007
using namespace std;
vector<long long int> factor;
long long int ans = 0;
/*
1
2 3
1 -4
8 2 -2
*/
struct primeFactorization 
{
	int countOfPf, primeFactor;
};
int spf[MAX];
void calcSpf()
{
	spf[1] = 1;
	for (int i = 1; i < MAX; i++)
		spf[i] = i;
	for (int i = 4; i < MAX; i += 2)
		spf[i] = 2;

	for (int i = 3; i*i < MAX; i++)
	{
		if (spf[i] == i)
		{
			for (int j = i * i; j < MAX; j += i) // j+=i;
			{
				
				if ( j == spf[j] )
				{
					spf[j] = i;
				}
				
			}
		}
	}
}

void genDiv(vector<primeFactorization> a,long long int c,long long int d, int n) 
{

	if (c == a.size())
	{
		factor.push_back(d);
		/*if ([d] > 0 && [n / d] > 0) // running twice !!
		{
			ans++;
		}*/
		//cout << d << " ";   // if factor is 2 then remove n/2 also!!
		return;
	}

	for (int i = 0; i <= a[c].countOfPf; i++)
	{
		genDiv(a, c + 1, d,n);
		d *= a[c].primeFactor;
	}
}

void find(int n)
{
	long long int temp = (long long int)n * n;
	vector<primeFactorization> a;
	int count = 0;
	for (int i = spf[n]; n != 1; i = spf[n])
	{
		count = 0;
		while (n % i == 0)
		{
			n /= i;
			count++;
		}
		a.push_back({ 2 * count, i });
	}
	long long int curIndex = 0, curDiv = 1;
	genDiv(a, curIndex, curDiv, temp);
}

void solve(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		find(v[i]);
	}
}

int main()
{
	calcSpf();
	int t;
	cin >> t;
	while (t--)
	{

		int n,m;
		cin >> n >> m;
		int xflag = 0,yflag = 0;
		vector<int> vxp, vxn, vyp, vyn;
		vector<int> mxp(MAX), myp(MAX), mxn(MAX), myn(MAX);
		ans = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			if (x > 0)
			{
				mxp[x]++;
				vxp.push_back(x);
			}
			else if (x < 0)
			{
				x = -x;
				mxn[x]++;
				vxn.push_back(x);
			}
			else
				xflag = 1;
		}
		for (int i = 0; i < m; i++)
		{
			int x;
			cin >> x;
			if (x > 0)
			{
				myp[x]++;
				vyp.push_back(x);
			}
			else if (x < 0)
			{
				x = -x;
				myn[x]++;
				vyn.push_back(x);
			}
			else
				yflag = 1;
		}
		
		for (int i = 1; i < MAX; i++)
		{
			factor.clear();
			if (mxp[i] > 0 || mxn[i] > 0 || myp[i] > 0 || myn[i] > 0)
			{
				find(i);
				long long int r = (long long)i * i;
				int total = 0;
				if (mxp[i] > 0)
					total++;
				if (mxn[i] > 0)
					total++;
				
				if (total > 0)
				{
					for (int j = 0; j < factor.size(); j++)
					{
						long long int w1 = factor[j];
						long long int w2 = r / w1;
						if(w1<MAX && w2<MAX)
						if (myp[w1] > 0 && myn[w2] > 0)
							ans += total;
					}
				}

				total = 0;
				if (myp[i] > 0)
					total++;
				if (myn[i] > 0)
					total++;

				if (total > 0)
				{
					for (int j = 0; j < factor.size(); j++)
					{
						long long int w1 = factor[j];
						long long int w2 = r / w1;
						if (w1 < MAX && w2 < MAX)
						if (mxp[w1] > 0 && mxn[w2] > 0)
							ans += total;
					}
				}
			}

		}

		if (xflag == 1)
		{
			ans += ((long long int)n - 1) * m;
		}
		else if (yflag == 1)
		{
			ans += n * ((long long int)m - 1);
		}
		cout << ans << endl;
	}
}
