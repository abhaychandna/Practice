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
#include<list>

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

vector<vector<pair<int, int>>> adj;
ll V, E;
ll INF = INT_MAX;
typedef pair<int, int> iPair;

void dijkstra(int s, vl & d, vl & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}
void shortestPathingraph(int src, vl&da)  
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V+1, INF);  
    pq.push(make_pair(0, src)); 
    dist[src] = 0;
    while (!pq.empty()) { 
        int u = pq.top().second;
        pq.pop();
        
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second; 
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    } 
    for (int i = 0; i <= V; ++i)
        da[i] = dist[i]; 
}
ll Ynot()
{
    
	ll ans = 1e12;
    ll discount = 50;
    ll factor = 100 / discount;
    
    cin >> V >> E

    adj.resize(V + 1);
    for (int i = 0; i < adj.size(); i++)adj[i].resize(0);
    for (int i = 0; i < E; i++) {
        ll a, b, wt;
        cin >> a >> b >> wt;
        adj[a].push_back({ b, wt });
        adj[b].push_back({ a, wt });
    }

    ll start, end;
    cin >> start >> end;
    vl da(V+1), db(V+1);
    vl pa, pB;

    shortestPathingraph(start, da); 
    shortestPathingraph(end, db);

    for (int i = 1; i <= V; i++) {
        for (auto edge : adj[i]) {
            int j = edge.first;
            ll wt = edge.second/ factor;

            ans = min(ans, da[i] + db[j] + wt);
            //ans = min(ans, da[j] + db[i] + wt);
        }
    }
	return ans;
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

    int testFiles = 5;
    for (int fno = 0; fno < testFiles; fno++)
    {

        init(fno);
        //cout << cakewalk();
        int t = 1;
        cin >> t;
        while (t--)
        {
            ll ans = 0;
            ans = Ynot();
            cout << ans << endl;
        }

        inout();
    }
}