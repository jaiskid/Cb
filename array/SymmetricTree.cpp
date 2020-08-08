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
bool aremirror(TreeNode* a, TreeNode *b) {
	if (a == NULL and b == NULL )
		return true;
	if (a != NULL and b != NULL)
		return (a->val == b->val and aremirror(a->left, b->right) and aremirror(a->right, b->left));
	return false;
}
bool issymetric(TreeNode* root) {
	if (root == NULL)
		return true;
	return aremirror(root->left, root->right);
}
int main() {
	TreeNode* root = tree_build();
	cout << issymetric(root);
}