#include<iostream>
#include<vector>
using namespace std;
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int t;
	int siz = (2 * 1e5) + 20;
	cin >> t;
	while (t--)
	{
		int n, m;

		cin >> n >> m;
		//scanf("%d %d", &n, &m);
		vector<int> k(siz, 0);
		string s;
		cin >> s;
		//scanf("%s", &s);
		for (int i = 0; i < m; i++)
		{
			int x;
			cin >> x;
			//scanf("%d", &x);
			k[x]++;
		}

		vector<long long int> h(26, 0);
		//vector<int> p(n, 0);

		long long int count = 1;

		for (int i = n - 1; i >= 0; i--)
		{
			//p[i] += count;
			h[s[i] - 97] += count;
			count += k[i];
		}

		for (int i = 0; i < 26; i++)
		{
			cout << h[i] << " ";
			//printf("%d ", h[i]);
		}
		cout << endl;
	}
}