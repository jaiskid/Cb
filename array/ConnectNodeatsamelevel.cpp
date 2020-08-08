#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode* nextright;
	TreeNode(int x) : val(x), left(NULL), right(NULL), nextright(NULL) {}
};
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
TreeNode* connect(TreeNode *root) {
	stack<TreeNode*>q1, q2;
	q1.push(root);
	while (!q1.empty() || !q2.empty()) {
		while (!q1.empty()) {
			TreeNode* temp = q1.top(); q1.pop();
			if (!q1.empty()) {
				temp->nextright = q1.top(); q1.pop();
				if (temp ->left != NULL) {
					q2.push(temp->left);
				}
				if (temp->right != NULL) {
					q2.push(temp->right);
				}
			}
		}
		while (!q2.empty()) {
			TreeNode*temp = q2.top(); q2.pop();
			if (!q2.empty()) {
				temp->nextright = q2.top(); q2.pop();
				if (temp->left != NULL) {
					q1.push(temp->left);
				}
				if (temp->right != NULL) {
					q1.push(temp->right);
				}

			}
		}
	}
	return root;
}
void print(TreeNode * root) {
	if (root == NULL)
		return;
	cout << root->val << " ";
	print(root->left);
	print(root->right);
}
int main() {
	TreeNode* root = tree_build();
	// vector<int> result = inorderTraversal(root);
	root = connect(root);
	print(root);
}