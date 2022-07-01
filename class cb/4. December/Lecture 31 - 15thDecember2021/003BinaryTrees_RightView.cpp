
/*

given the pre-order traversal of a binary tree, output its right view.

Example 
	Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
	Output: 10 30 50 70
*/

#include<iostream>
#include<queue>

using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int data) {
		this->data = data;
		this->left = this->right = NULL;
	}
};

node* buildTree() {
	int x;
	cin >> x;

	if(x == -1) {
		node* root = NULL;
		// root represents an empty tree
		return root;
	}

	node* root = new node(x);
	root->left = buildTree();
	root->right=buildTree();

	return root;
}

void levelOrder(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		node* front = q.front(); q.pop();
		if(front == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << front->data << " ";
			if(front->left) q.push(front->left);
			if(front->right)q.push(front->right);
		}
	}
}

void rightView(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		node* front = q.front(); q.pop();
		if(front == NULL) {
			// cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		} else {
			if(!q.front()) {
				// q.front() == NULL
				cout << front->data << " ";
			}

			if(front->left) q.push(front->left);
			if(front->right)q.push(front->right);
		}
	}
}

int maxLevel = -1; // to store the maximum level upto which the
				   // rightMost node has been printed

void rightViewRecursive(node* root, int level) {
	if(root == NULL) {
		return;
	}

	if(maxLevel < level) {
		cout << root->data << " ";
		maxLevel = level;
	}
	rightViewRecursive(root->right, level+1);
	rightViewRecursive(root->left,  level+1);

}

int main() {

	node* root = NULL;
	root = buildTree();
	// rightView(root);
	levelOrder(root);
	rightViewRecursive(root, 0);
	
	return 0;
}