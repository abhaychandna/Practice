#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<cmath>

#define ll long long 
#define mod 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

#define vl vector<long long int>
#define vvl vector<vector<long long int>>
#define pl pair<long long int, long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define forev(i,n) for(int i=n-1;i>=0;i--)

using namespace std;

signed randomize(int len)
{
	return (rand() % len);
}


void cakewalk() {

	const int testFiles = 3;//3 (first 2 will be sample)
	const int maxT = 1e5;//1e4
	const int maxN = 1e6;//1e6

	for (int t = 1; t <= testFiles; t++)
	{
		string in = "cakewalk/in0" + to_string(t) + ".txt";
		freopen(&in[0], "w", stdout);
		//srand(t);
		int tests = randomize(maxT);
		cout << tests << endl;
		while (tests--)
		{
			for (int i = 0; i < 3; i++)
				cout << randomize(maxN) << " " << randomize(maxN) << endl;
		}

		fclose(stdout);
	}
}


void cricket() {
	const int testFiles = 3;//3 (first 2 will be sample)

	int n = 0;
	for (int t = 0; t < testFiles; t++) {
		string in = "cricket/in0" + to_string(t) + ".txt";
		freopen(&in[0], "w", stdout);
		
		cout << 20 << endl;
		for (int i = n; i < n+20; i++)cout << i << endl;
		n += 20;

		fclose(stdout);
	}
}


void microsoft() {

	const int testFiles = 3;//3 (first 2 will be sample)
	const int maxT = 5;//5
	const int maxN = 1e4;//1e4
	const int maxA = 1e3;//1e3
	const int limitN = 1e5;//1e5
	for (int t = 1; t <= testFiles; t++)
	{
		int sumN = 0;
		string in = "microsoft/in0" + to_string(t) + ".txt";
		freopen(&in[0], "w", stdout);
		//srand(t);
		int tests = maxT;
		cout << tests << endl;
		while (tests--)
		{
			int n = randomize(maxN);
			if (sumN + n > limitN) n = randomize(100);
			cout << n << endl;
			while (n--) {
				int a = randomize(maxA);
				if (rand() % 2)a *= -1;
				cout << a << " ";
			}
			cout << endl;
		}

		fclose(stdout);
	}
}

signed main()
{
	//cakewalk();
	cricket();
	//microsoft();

	return 0;
}

