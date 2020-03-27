#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n), b(n),c(n);
		map<int,int> m;
		int x = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			x = x xor a[i];
			
		}
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
			x = x xor b[i];
			m[b[i]]++;
		}
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			int temp = x xor a[i];
			if (m[temp] > 0)
			{
				m[temp]--;
				c[i] = temp;
				continue;
			}
			flag = 1;
			cout << "-1";
			break;
		}
		if(flag == 0)
		for (int i = 0; i < n; i++)
			cout << c[i] << " ";

		cout << endl;
	}
}