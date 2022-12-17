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

#define all(x) x.begin(),x.end()

using namespace std;

long long int tm = 0;
long long int ans = 0;
vector<pair<string, vector<string>>> finished;

class Project {
public:
	string name;
	int duration;
	int score;
	int deadline;
	int r_cnt;
	vector<pair<string, int>> roles;
};

bool comp(Project a, Project b) {
	return a.score > b.score;
}

class Contributor {

public:
	string name;//contributor's name
	int r_cnt;// input is given as N
	vector<pair<string, int>> roles;

};

map < string, set<pair<int, string>>>skill;
map<pair<string, string>, int> ds;
bool check(string s, int level, set<string>& names, vector<string> &v) {
	auto it = skill[s].lower_bound(make_pair(level, "0"));

	while (it != skill[s].end() && names.find((*it).second) != names.end()) {
		it++;
	}

	if (it == skill[s].end()) {
		return 0;
	}

	names.insert((*it).second);
	v.push_back((*it).second);
	return 1;

	//return 0;
}


void learn(vector<pair<string, int>> &roles, vector<string> &v) {
	int j = 0;
	for (int i = 0; i < roles.size();i++) {
		auto role = roles[i];
		int lvl = ds[make_pair(role.first, v[j])];

		//map < string, set<pair<int, string>>>skill;
		auto it = skill[role.first].find({ lvl, v[j] });
		if (lvl <= role.second) {
			ll k = (*it).first;
			k++;
			skill[role.first].erase(it);
			skill[role.first].insert(make_pair(k, v[j]));

			ds[make_pair(role.first, v[j])]++;
		}
		j++;

	}
	//change 95 also
}
int complete(Project p) {

	int i = 0;
	set<string> names;
	vector<string> v;
	for (i = 0; i < p.roles.size(); i++) {
		auto role = p.roles[i];
		if (!check(role.first, role.second, names, v))break;
	}
	if (i == p.roles.size()) {
		learn(p.roles, v);

		finished.push_back({ p.name,v });

		return 1;
	}

	return 0;
}

int cont_cnt, project_cnt;
ll Ynot()
{
	ans = 0;
	tm = 0;

	cin >> cont_cnt >> project_cnt;
	vector<Project>project(project_cnt);
	vector<Contributor>contributor(cont_cnt);
	for (int i = 0; i < cont_cnt; i++) {
		cin >> contributor[i].name;
		cin >> contributor[i].r_cnt;
		for (int j = 0; j < contributor[i].r_cnt; j++) {
			string s;
			int l;
			cin >> s >> l;
			ds[make_pair(s, contributor[i].name)] = l;
			contributor[i].roles.push_back({ s,l });
			skill[s].insert({ l,contributor[i].name });
		}
	}
	for (int i = 0; i < project_cnt; i++) {
		cin >> project[i].name;
		cin >> project[i].duration;
		cin >> project[i].score;
		cin >> project[i].deadline;
		cin >> project[i].r_cnt;
		for (int j = 0; j < project[i].r_cnt; j++) {
			string s; int x;
			cin >> s >> x;
			project[i].roles.push_back({ s,x });
		}
	}

	sort(all(project), comp);

	int i = 0;
	vector<bool> vis(project_cnt);
	int y = 0;
	while (i < project_cnt && y<500) {
		while (i < project_cnt && (vis[i] || !complete(project[i])))i++;
		if (i >= project_cnt)break;
		//complete(projects[i], contributor);
		tm += project[i].duration;
		if (tm <= project[i].deadline) ans += project[i].deadline;
		else ans += max(0ll, tm - project[i].deadline);
		vis[i] = true;
		i = 0;
		y++;
	}

	//cout << ans << '\n';
	cout << ans << '\n';
	cout << finished.size() << '\n';
	for (auto f : finished) {
		cout << f.first << '\n';
		for (auto it : f.second) {
			cout << (it) << " ";
		}
		cout << '\n';
	}
	return -11;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("d_dense_schedule.in.txt", "r", stdin);
	freopen("output4.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	//cin >> t;
	while (t--)
	{
		ll a = 0;
		a = Ynot();
		//cout << a << '\n';
	}
}