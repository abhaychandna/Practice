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

int k(vector<int> stones, int cap) {
	int sum = 0,cnt=0;
	sort(stones.begin(), stones.end());
	int n = stones.size();
	int low = 0, high = n - 1;
	while (low <= high) {
		int sum = 0;
		while (low <= high) {
			if (sum + stones[high] > cap)break;
			sum += stones[high--];
		}
		while (low <= high) {
			if (sum + stones[low] > cap)break;
			sum += stones[low++];
		}
		cnt++;
	}
	return cnt;
}
struct Node {
	Node* left;
	Node* right;
	int data;
};

struct LLNode
{
	LLNode* next=NULL;
	Node* data;
};

LLNode* kk(Node* root) {
	
	queue<Node*> q;
	q.push(root);

	LLNode* head = new LLNode();
	LLNode* start = head;

	while (!q.empty())
	{
		queue<Node*> q2;
		int mx = -1;
		Node* nxt = NULL;
		while (!q.empty()) {
			auto x = q.front();
			q.pop();

			if (x->data > mx) {
				nxt = x;
				mx = x->data;
			}

			if (x->left) {
				q2.push(x->left);
			}
			if (x->right) {
				q2.push(x->right);
			}

		}
		q = q2;
		LLNode* p = new LLNode();
		p->data = nxt;
		p->next = NULL;
		head->next = p;
		head = head->next;
	}
	start = start->next;
	return start;
}


int LeftSum2(Node* root, int &k, int &cnt) {
	if (root == NULL)return 0;
	int sum = LeftSum2(root->left,k,cnt);
	if (sum >= k)cnt++;
	int tmp = LeftSum2(root->right,k,cnt);
	return sum+root->data;
}

int LeftSum(Node* root, int k)
{
	int ans = 0;
	int tmp = LeftSum2(root, k, ans);
	return ans;
}

ll Ynot()
{
	ll ans = 0;

	return ans;
}

int main()
{
	vector<int> v = {1,2,8,9};
	int c = 10;
	cout << k(v, c);

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