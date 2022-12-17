#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>

#define ll long long 
#define mod 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

#define vi vector<int>
#define vl vector<long long int>
#define vvi vector<vector<int>> 
#define vvl vector<vector<long long int>>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define fos(i,start,end,step) for(int i=start;i<end;i+=step)

using namespace std;

struct Node {
	ll data;
	struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node = new Node;

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

ll solve()
{
	ll ans = 0;
	int n;
	cin >> n;
	vl v(n);
	struct Node* head = new Node;
	head->data = 1;
	struct Node* x = new Node;
	head->next = x;
	fo(i, n) {
		cin >> v[i];
		struct Node* p = new Node;
		x->data = v[i];
		x->next = p;
		x = p;
	}
	x->data = 1;
	x->next = NULL;
	ll gans = 0;
	while (true) {
		struct Node* temp = head;
		struct Node* prev = head;
		temp = temp->next;
		
		if (temp->next == NULL) break;
		struct Node* nxt = temp->next;

		struct Node* k = temp;
		struct Node* kp = prev;
		struct Node* kn = nxt;
		ans = prev->data * temp-> data* nxt->data;

		while (nxt->next != NULL) {
		
			ll r = prev->data * temp->data * nxt->data;
			if (r > ans) {
				ans = r;
				kp = prev;
				kn = nxt;
				k = temp;
			}
			prev = temp;
			temp = nxt;
			nxt = nxt->next;
		}

		kp->next = kn;
		gans += ans;
	}

	cout << gans << '\n';
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
		ans = solve();
		//cout << ans << '\n';
	}
}