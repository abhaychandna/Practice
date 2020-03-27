#include<iostream>
#include<vector>
#include<map>
#define MAX 100007
int spf[MAX];
using namespace std;

void sieve()
{
	spf[1] = 1;
	for (int i = 2; i < MAX; ++i)
		spf[i] = i;
	for (int i = 4; i < MAX; i += 2)
		spf[i] = 2;

	for (int i = 3; i*i < MAX; i++)
	{
		if (spf[i] == i)
		{
			for (int j = i * i; j < MAX; j += i)
			{
				if (spf[j] == j)
					spf[j] = i;
			}
		}
	}
}

vector<int> factorize(int x)
{
	int y = x;
	vector<int> b;
	//if (x == 2)
		//b.push_back(2);
	/*int n = 1;
	int temp = spf[x];
	
	x /= spf[x];
	if (x == 1)
		b.push_back(y);*/
	int n = 0;
	int temp = spf[x];
	while (x != 1)
	{
		/*
		if (temp != spf[x])
		{
			if (n % 2 == 1)
			{
				b.push_back(spf[x]);
			}
			n = 0; 
			temp = spf[x];
		}
		
		x /= spf[x];
		n++;*/
		if (spf[x] == temp)
		{
			n++;
			x /= spf[x];
		}
		else
		{
			if (n % 2 != 0)
				b.push_back(temp);
			temp = spf[x];
			x /= spf[x];
		}

	}
	if(n%2 != 0 )
		b.push_back(temp);
	if (b.empty())
		b.push_back(1);

	return b;
}

int main()
{

	sieve();
	
	//vector<int> x;
	//x = factorize(5);
	/*for (int i = 1; i < MAX; i++)
	{
		vector<int> temp = factorize(i);
		
	}*/

	int t;
	cin >> t;
	
	while (t--)
	{
		int n,n2;
		cin >> n >> n2;
		map<vector<int>, vector<int>> mx,my;
		map<int, int> ax, ay;
		vector<int> x, y;
		
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			if (a < 0)
			{
				x.push_back(a);
				ax[-a]++;
			}
			else
			{
				vector<int> temp = factorize(a);
				mx[temp].push_back(a);
				ax[a]++;
			}
		}
		for (int i = 0; i < n2; i++)
		{
			int a;
			cin >> a;
			if (a < 0)
			{
				y.push_back(a);
				ay[-a]++;
			}
			else
			{
				vector<int> temp = factorize(a);
				my[temp].push_back(a);
				ay[a]++;
			}
		}
		long long int ans = 0;
		for (int i = 0; i < x.size(); i++)
		{
			int r = -x[i];
			vector<int> temp = factorize(r);
			if (!mx[temp].empty())
			{
				for (int j = 0; j < mx[temp].size(); j++)
				{
					if (ay[mx[temp][j] * x[i]])
					{
						ans += ay[mx[temp][j] * x[i]];
					}
				}
			}
		}
		for (int i = 0; i < y.size(); i++)
		{
			int r = -y[i];
			vector<int> temp = factorize(r);
			if (!mx[temp].empty())
			{
				for (int j = 0; j < mx[temp].size(); j++)
				{
					if (ay[mx[temp][j] * x[i]])
					{
						ans += ay[mx[temp][j] * x[i]];
					}
				}
			}
		}


		cout << ans << endl;//add condtion for 0,0;
	}
}