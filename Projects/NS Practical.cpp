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

ll Ynot()
{
	ll ans = 0;

	return ans;
}


string headings = "PQDFKL";
//map<char, int> col_map;
pair<int, int> find_in_vector(vector<vector<char>>& v, char c) {
	for (int i = 0; i < v.size(); i++) {
		for(int j=0;j<v[i].size();j++)
			if(v[i][j]==c)return {i,j};
	}
}

string f(string s, vector<vector<char>>& pf) {
	string res = "";
	for (auto& c : s) {
		auto rc = find_in_vector(pf, c);
		res += headings[rc.first];
		res += headings[rc.second];
	}
	return res;
}

string f2(string s, string key) {
	vector<vector<char>> v;
	int k = 0;
	int col_sz = key.size();
	while (k < s.size()) {
		vector<char> temp;
		for (int i = 0; i < col_sz; i++) {
			if (k < s.size()) {
				temp.push_back(s[k]);
				k++;
			}
			else {
				temp.push_back('X');
			}
		}
		v.push_back(temp);
	}
	vector<pair<char,int>> key_map;
	for(int i=0;i<key.size();i++){
		key_map.push_back({key[i],i});
	}
	sort(key_map.begin(), key_map.end());
	string res = "";
	for (int i = 0; i < key_map.size(); i++) {
		int col = key_map[i].second;
		for(int j=0;j<v.size();j++){
			res += v[j][col];
		}
	}
	return res;
}

int main()
{
	string s = "AFKOR";
	vector<vector<char>> pf = { {'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','Q','R'} };
	string b = f(s, pf);
	cout << b << endl;
	
	string key = "ABHAY";
	string s2 = "ASNDASNFLKASFNHBGLH";
	string c = f2(s2, key);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--)
	{
		ll ans = 0;
		ans = Ynot();
		cout << ans << '\n';
	}
}