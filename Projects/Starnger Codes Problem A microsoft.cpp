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

ll microsoft()
{
	/*
	
	There is an array of N numbers. You need to split the array in different parts (not necessarily of equal size).
	Let A1 be the sum of elements in first part, A2 the sum of elements in second and so on. 
	The goodness value of the array A is A1 - A2 + A3 - A4 + A5 ...
	Find the maximum goodness value which can be achieved after splitting the array in an optimal manner. 

	Sum of N in all testcases do not exceed 10^6
	
	Constraints 
	1<=T<=10^3
	1<=N<=10^5
	-10^3<=Ai<=10^3

	Input:
	First line contain T number of testcases.
	Each testcase contains two lines
	First line contain N, length of the array
	Second line contains N numbers, elements in the array

	Sample Input
	
	4
	1 2 -3 4 5 
	1 -2 -3 4 -5 -6
	-1 2 3 -4 5 6
	-1 2 3 4 5 -6

	Sample Output 

	15
	15
	13
	13

	Explanation 

	15 -  (1 2 | -3 | 4 5)
			A1   A2	  A3
			A1 = 1+2 = 3, A2 = -3, A3 = 4+5 = 9
			A1 - A2 + A3 = 15
	21 -  (1 | -2 -3 | 4 | -5 -6)
		   A1	A2	  A3	A4
		   A1 = 1, A2 = -2 -3 = -5, A3 = 4, A4 = -5 -6 = -11
		   A1 - A2 + A3 - A4 = 21
	19 -  (-1 2 3 | -4 | 5 6)
			A1	    A2	   A3	
			A1 = -1 + 2 + 3, A2 = -4 = -4, A3 = 5 + 6 = 11
			A1 - A2 + A3  = 19
	21 -  (-1 2 3 4 5 | -6)
			A1			A2
			A1 = -1 +2 +3 +4 +5 = 13, A2 = -6
			A1 - A2 = 21
			A2 = 2
			A1  = 
	
	Sample Input
	
	2
	-3 7 12 -10 8
	3 7 12 -10 8
	
	Sample Output

	34
	40
	
	*/
	ll ans = 0;

	ll n;
	cin >> n;
	vector<ll> v(n); 
	fo(i, n)cin >> v[i];
	
	ans += v[0];
	for (int i = 1; i < n; i++)
		ans += abs(v[i]);

	// if negative is there new split, till numbers are negtive, 
	// if positive are there , new split untilnegative comes
	return ans;
}

ll cricket()
{
	/*
	In one ball, the team can only score either 1,2,3,4 or 6 runs. If a team scores N runs and 
	scores some runs in every ball, determine the no. of possible combinations for the team to 
	reach the score.

	Constraints
	1<=T<=60
	1<=N<=60
	
	Input:
	First line contain T number of testcases.
	Each testcase contains one line
	First line contains N, runs scored by the team.
	

	Sample Input
	
	4
	1 
	2 
	3 
	4

	Sample Output

	1
	2
	4
	8

	Explanation

	1 - Possible Combinations - {1} 
	2 - Possible Combinations - {1,1} , {2}
	4 - Possible Combinations - {1,1,1} , {1,2} , {2,1} , {3}
	8 - Possible Combinations - {1,1,1,1} , {1,1,2} , {1,2,1} , {2,1,1} , {2,2} , {1,3} , {3,1} , {4}  
	
	Sample Input
	
	3
	6
	25
	47

	Sample Output
	
	30
	9455922
	22188630047309
	*/
	ll n;
	cin >> n;
	
	vector<ll> runs = { 1,2,3,4,6 };
	vector<ll> dp(n+6);

	dp[0] = 1;
	//dp[1] = dp[2] = dp[3] = dp[4] = dp[6] = 1;
	for (int i = 0; i < n; i++) {
		for (auto run : runs) {
			dp[i + run] += dp[i]; // overflowing for  n = 67
		}
	}
	
	//altrate soln (back propagation)
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		for (auto run : runs) {
			if (i - run >= 0)dp[i] += dp[i - run]; // overflowing for  n = 67
		}
	}
	
	return dp[n];
}

bool cakewalk() {
	/*
	Sample Input
	
	3
	1 2 
	8 0
	5 2 
	0 0
	7 3
	2 2 
	4 5
	4 7
	4 6

	Sample Output
	
	0
	1
	0
	*/
	ll a[2], b[2], c[2];
	cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];
	ll distA = (abs(a[0] - c[0]) + abs(a[1] - c[1]));
	ll distB = max(abs(b[0] - c[0]), abs(b[1] - c[1]));
	return distA < distB;
}

void init(int fno) {
	string ou = "cakewalk/out0" + to_string(fno) + ".txt";
	string in = "cakewalk/in0" + to_string(fno) + ".txt";
	freopen(&in[0], "r", stdin);
	freopen(&ou[0], "w", stdout);
}
void inout() {
	fclose(stdout);
	fclose(stdin);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int testFiles = 3;
	for (int fno = 0; fno < testFiles; fno++)
	{
		
		init(fno);
		//cout << cakewalk();
		int t = 1;
		cin >> t;
		while (t--)
		{
			ll ans = 0;
			ans = cakewalk();
			cout << ans << endl;
		}

		inout();
	}
}