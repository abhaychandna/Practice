#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

void topView(Node* root,int &hd, map<int,int> &res) {
    if (root == NULL)return;
    hd++;
    topView(root->right,hd,res);
    hd -= 2;
    topView(root->left, hd, res);
    hd++;
    res[hd] = root->val;
    return;
}


int main()
{
    topView(head);

    return 0;
}
