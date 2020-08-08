#include<bits/stdc++.h>
using namespace std;
class Node {
public:
	int data;
	Node *left, *right, *next;
	Node(int data) {
		this->data = data;
		this->left = this->right = this->next = NULL;
	}
};
//function to set next pointer of all nodes in a binary tree
//curr ->current node;
//prev = previous processed node passed by reference

void setNextNode(Node* curr , Node* &prev) {
	//return if tree is empty
	if (curr == NULL)
		return;
	//recur for the left subtree
	setNextNode(curr->left, prev);

	//set previous node next pointer to current node
	if (prev != NULL) {
		prev->next = curr;
	}
	//update previous node to current node
	prev = curr;
	//recure for the right subtree
	setNextNode(curr->right, prev);

}
void inorderSuccessor(Node* curr) {
	Node*prev = NULL;
	//set next pointer of all nodes
	setNextNode(curr, prev);
	//go to left most node
	curr = curr->left->left;
	while (curr ->next) {
		cout <<"Inorder Successor "<< curr->data << " " << curr->next->data << endl;
		curr = curr->next;
	}
}
int main() {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);

	inorderSuccessor(root);
}