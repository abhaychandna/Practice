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
/*
void cryptArithemetic(string s1, string s2, string s3) {
	int n1 = s1.length();
	int n2 = s2.length();
	int n3 = s3.length();
	int n = max(n1, max(n2, n3));
	int carry = 0;
	int sum = 0;
	int i = n1 - 1;
	int j = n2 - 1;
	int k = n3 - 1;
	while (k >= 0) {
		sum = carry;
		if (i >= 0) {
			sum += s1[i] - '0';
		}
		if (j >= 0) {
			sum += s2[j] - '0';
		}
		carry = sum / 10;
		sum = sum % 10;
		if (sum != s3[k] - '0') {
			cout << "false" << endl;
			return;
		}
		i--;
		j--;
		k--;
	}
	if (carry != 0) {
		cout << "false" << endl;
		return;
	}
	cout << "true" << endl;
}
*/

string a, b, c;

void fillmap(string &s, map<char, int> &letters) {
	for (auto& c : s)letters[c] = 1;
}

int convert(string &s, map<char, int> &mp) {
	int res = 0;
	for (auto& c : s) {
		res = (res * 10) + mp[c];
	}
	return res;
}

bool check(vector<char>& v, vector<int> &digits) {
	map<int, int> vis;
	for (int j = 0; j < digits.size(); j++) {
		if (vis.find(digits[j]) != vis.end()) return false;
		vis[digits[j]] = 1;
	}
	map<char, int> mp;
	for (int i = 0; i < v.size(); i++)mp[v[i]] = digits[i];

	int anum = convert(a, mp);
	int bnum = convert(b, mp);
	int cnum = convert(c, mp);
	if ((anum + bnum) == cnum)return true;
	return false;
}

bool recur(int i, vector<char>& v, vector<int> &digits) {
	if (i == v.size()) {
		if (check(v, digits)) {
			cout << "Answer found\n";
			for (auto& k : digits)cout << k << " ";
			return true;
		}
		return false;
	}
	for (int k = 0; k <= 9; k++) {
		digits.push_back(k);
		if (recur(i + 1, v, digits))return true;
		digits.pop_back();
	}
	return false;
}

void cryptArithemetic(string s1, string s2, string s3) {

	a = s1;
	b = s2;
	c = s3;

	int n1 = s1.length();
	int n2 = s2.length();
	int n3 = s3.length();
	
	map<char, int> mp;
	
	map<char, int> letters;
	fillmap(s1, letters);
	fillmap(s2, letters);
	fillmap(s3, letters);
	
	vector<char> v;
	for (auto& it : letters) {
		v.push_back(it.first);
	}
	vector<int> digits;
	recur(0,v,digits);
}
ll Ynot()
{
	ll ans = 0;
	string s1 = "comes";
	string s2 = "she";
	string s3 = "here";
	cryptArithemetic(s1, s2, s3);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	//cin >> t;
	while (t--)
	{
		ll ans = 0;
		ans = Ynot();
		cout << ans << '\n';
	}
}