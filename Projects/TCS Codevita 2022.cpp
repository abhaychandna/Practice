#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<cmath>
#include<sstream>

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
map<string, bool> vis;
map<string, Person> mp;

class Person {
public:
	string name;
	string mname;
	string fname;
	vector<Person*> parent;
	int bday;
	int dday = 9999;
	bool glitz=false;

	void set_parent() {
		if (mname != "Unknown")parent.push_back(mp[mname]);
		if (fname != "Unknown")parent.push_back(mp[fname]);
	}

	void set_glitz() {
		for (auto p : parent) {
			if (!(p->bday + 18) <= this->bday && (p->bday + 50 >= this->bday))glitz = true;
		}
		if (parent.size() == 2) {
			if ((abs(parent[0]->bday - parent[1]->bday)) > 20) glitz = true;
		}
	}

};

bool dfs(Person* p) {
	vis[p->name] = true;
	bool glitz = false;
	for (auto par : p->parent) {
		if (!vis[par->name]) {
			glitz |= dfs(par);
		}
	}
	if (!p->glitz)cout << p->name << '\n';
	return glitz | p->glitz;
}

void event(string s) {
	vector<string> v;

	stringstream s2(s);
	v = {};
	for (string i; s2 >> i;) {
		v.push_back(i);
		if (s2.peek() == ',')
			s2.ignore();
	}
	
	if (v[0] == "BI") {
		Person p = Person();
		p.bday = stoi(v[1]);
		p.name = v[2];
		p.fname = v[3];
		p.mname = v[4];
		p.set_parent();
		p.set_glitz();
	}

	if (v[0] == "DE") {
		auto it = mp.find(v[1]);
		Person p = mp;
		p.bday = stoi(v[1]);
		p.name = v[2];
		p.fname = v[3];
		p.mname = v[4];
		p.set_parent();
		p.set_glitz();
	}
}
ll Ynot()
{
	ll ans = 0;

	return ans;
}

int main()
{
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