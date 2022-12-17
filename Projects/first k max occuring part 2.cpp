#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
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

struct Node {
	int cnt;
	string key;
};

struct Trie {
	int cnt = 0;
	string key;

	unordered_map<char, Trie*> character;
};

Trie* getTrieNode() {
	Trie* node = new Trie();
	node->cnt = 0;
	node->key = "";
	return node;
}

void insert_trie(Trie* head, string word) {

	Trie* curr = head;
	for (auto ch : word) {
		if (curr->character.find(ch) == curr->character.end()) {
			Trie* node = new Trie();
			curr->character[ch] = getTrieNode();
		}
		curr = curr->character[ch];
	}

	curr->cnt++;
	curr->key = word;
}

struct comp {
	bool operator() (const Node* lhs, const Node* rhs) {
		return lhs->cnt < rhs->cnt;
	}
	bool operator() (const Trie* lhs, const Trie* rhs) {
		return lhs->cnt < rhs->cnt;
	}
};

void preorder_trie(Trie* head, priority_queue<Trie*, vector<Trie*>, comp>& pq) {
	for (int i = 0; i < 26; i++) {
		char ch = 'a' + i;
		if (head->character.find(ch) != head->character.end())
			preorder_trie(head->character[ch], pq);
	}

	if (head->cnt > 0) {
		pq.push(head);
	}
	return;
}

vector<string> findKfrequentWords(vector<string> v, int n, int k) {
	vector<string> ans;

	Trie* head = new Trie();
	for (auto word : v)
		insert_trie(head, word);

	priority_queue<Trie*, vector<Trie*>, comp> pq;
	preorder_trie(head, pq);

	while (k-- && !pq.empty()) {
		ans.push_back(pq.top()->key);
		cout << ans[ans.size() - 1] << " "<< pq.top()->cnt<< '\n';
		pq.pop();
	}
	return ans;

}


ll Ynot()
{
	ll ans = 0;

	return ans;
}

int main()
{


	vector<string> dict =
	{
		"code", "coder", "coding", "codable", "codec", "codecs", "coded",
		"codeless", "codec", "codecs", "codependence", "codex", "codify",
		"codependents", "codes", "code", "coder", "codesign", "codec",
		"codeveloper", "codrive", "codec", "codecs", "codiscovered"
	};

	int k = 50;

	// total number of keys
	int n = sizeof(dict) / sizeof(dict[0]);

	findKfrequentWords(dict, n, k);


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