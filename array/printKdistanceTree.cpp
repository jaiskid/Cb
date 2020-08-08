#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
vector<int> inorderTraversal(TreeNode*root) {
	stack<TreeNode*>s;
	TreeNode *curr = root;
	vector<int> res;
	while (curr != NULL || s.empty() == false) {
		while (curr != NULL) {
			s.push(curr);
			curr = curr->left;
		}
		curr = s.top();
		s.pop();
		res.emplace_back(curr->val);
		curr = curr->right;
	}
	return res;
}
*/
TreeNode* tree_build() {
	int x;
	cin >> x;
	if (x == -1) {
		return NULL;
	}
	TreeNode* curr = new TreeNode(x);
	curr->left = tree_build();
	curr->right = tree_build();
	return curr;
}
void printkdistanceDown(TreeNode*root , int k) {
	if (root == NULL || k < 0)
		return;
	if (k == 0) {
		cout << root->val << endl;
		return;
	}
	//print the left subtree and right subtree
	printkdistanceDown(root->left, k - 1);
	printkdistanceDown(root->right, k - 1);
}
int printkdistanceNode(TreeNode* root, int target, int k) {
	if (root == NULL)
		return -1;
	if (root->val == target) {
		printkdistanceDown(root, k);
		return 0;
	}
	int dl = printkdistanceNode(root->left, target, k);
	if (dl != -1) {
		if (dl + 1 == k)
			cout << root->val << endl;
		else
			printkdistanceDown(root->right, k - dl - 2);
		return 1 + dl;
	}
	int dr = printkdistanceNode(root->right, target, k);
	if (dr != -1) {
		if (dr + 1 == k)
			cout << root->val << endl;
		else printkdistanceDown(root->left, k - dr - 2);
		return 1 + dr;
	}
	return -1;
}
int main() {
	TreeNode* root = tree_build();
	int target, k;
	cin >> target >> k;
	cout << printkdistanceNode(root, target, k);
	
}