/*

Implementation of the TRIE data structure to store strings.

Motivation :

Given an array of N strings, and an array of Q queries, check for each query if it
it present in the array or not.

*/

#include<iostream>
#include<unordered_map>

using namespace std;

class node {

public:

	char ch;
	bool terminal;
	unordered_map<char, node*> childMap;

	node(char ch) {
		this->ch = ch;
		this->terminal = false;
	}

};

class trie {
	node* root;

	public :

		trie() {
			root = new node('\0');
		}

		void insert(string str) {
			node* temp = root;
			for(char ch : str) {
				if(temp->childMap.find(ch) == temp->childMap.end()) {
					// temp node doesn't have a child node with the value ch
					node* n = new node(ch);
					temp->childMap[ch] = n;
					temp = temp->childMap[ch];
				} else {
					// temp node has a child node with the value ch
					temp = temp->childMap[ch];
				}
			}
			temp->terminal = true;
		}

		bool search(string str) {
			node* temp = root;
			for(char ch : str) {
				if(temp->childMap.find(ch) == temp->childMap.end()) {
					return false;
				}
				temp = temp->childMap[ch];
			}
			return temp->terminal;
		}
};

int main() {

	string words[] = {"code", "coder", "coding",
                      "news", "newspaper", "newsdesk",
                      "cruze", "cruise"};

    string queries[] = {"coder", "codes", "news", "new", "cruise"};

	trie t;

	for(string word : words) {
		t.insert(word);
	}

	for(string query : queries) {
		t.search(query) ? cout << query << " : true" << endl :
		                  cout << query << " : false" << endl;
	}

	return 0;
}
/*

Implementation of the TRIE data structure to store non-negative integers.

Assume integer has 32-bit representation.

*/

#include<iostream>

using namespace std;

class node {

	public :

	bool terminal;
	node* left; // indicates if node has a child that represents bit 0
	node* right;// indicates if node has a child that represents bit 1

	node() {
		this->terminal = false;
		this->left = this->right = NULL;
	}

};

class trie {
	node* root;

	public :
		trie() {
			root = new node();
		}

		void insert(int x) {
			node* temp = root;
			for(int i=31; i>=0; i--) {
				int bit = (x>>i)&1;
				if(!bit) {
					// ith bit of x is 0
					if(!temp->left) {
						// temp node does not have a left child
						node* n = new node();
						temp->left = n;
						temp = temp->left;
					} else {
						// temp node has a left child
						temp = temp->left;
					}

				} else {
					// ith bit of x is 1
					if(!temp->right) {
						// temp node does not have a right child
						node* n = new node();
						temp->right = n;
						temp = temp->right;
					} else {
						// temp node has a right child
						temp = temp->right;
					}
				}
			}

			temp->terminal = true;
		}

		bool search(int x) {
			node* temp = root;
			for(int i=31; i>=0; i--) {
				int bit = (x>>i)&1;
				if(!bit) {
					// ith bit is 0
					if(!temp->left) {
						return false;
					}
					temp = temp->left;
				} else {
					// ith bit is 1
					if(!temp->right) {
						return false;
					}
					temp = temp->right;
				}
			}
			return temp->terminal;
		}
};

int main() {

	int A[] = {25, 10, 2, 8, 5, 3};
	int n = sizeof(A) / sizeof(int);

	trie t;

	for(int i=0; i<n; i++) {
		t.insert(A[i]);
	}

	int B[] = {1, 2, 5, 10, 25, 0};
	int m = sizeof(B) / sizeof(int);

	for(int i=0; i<m; i++) {
		t.search(B[i]) ? cout << B[i] << " : true " << endl :
		                 cout << B[i] << " : false" << endl;
	}

	return 0;
}
/*

Given an array of non-negative integers of size n, find the maximum possible XOR between
any two numbers present in the array.

Example:
	Input : A[] = {25, 10, 2, 8, 5, 3}
	Output: 28
	Explaination: The maximum result is 5 ^ 25 = 28

	Input: A[] = {1, 2, 3, 4, 5, 6, 7}
	Output: 7
	Explaination: The maximum result is 1 ^ 6 = 7

*/

#include<iostream>
#include<climits>

using namespace std;

class node {
public:
	node* left;  // indicates if node has a child that represents bit 0
	node* right; // indicates if node has a child that represents bit 1

	node() {
		this->left = NULL;
		this->right= NULL;
	}
};

class trie {
	node* root;
public:
	trie() {
		root = new node();
	}

	void insert(int n) {
		node* temp = root;
		for(int i=31; i>=0; i--) {
			int bit = (1<<i)&n;
			if(!bit) {
				// ith bit of n is 0, check if temp node has a left child or not
				if(!temp->left) {
					node* n = new node();
					temp->left = n;
				}
				temp = temp->left;
			} else {
				// ith bit of n is 1, check if temp node has a right child or not
				if(!temp->right) {
					node* n = new node();
					temp->right = n;
				}
				temp = temp->right;
			}
		}
	}

	// return the maximum possible xor involving n
	int helper(int n) {
		node* temp = root;
		int XOR = 0; // to store the maximum possible XOR involving n
		int x_k = 0; // to store the integer with which we get maximum possible XOR involving A[i] i.e n
		for(int i=31; i>=0; i--) {
			int bit = (1<<i)&n;
			if(!bit) {
				// ith bit of n is 0
				if(temp->right) {
					// temp node has a right child, therefore ith bit of XOR can be 1
					XOR += (1<<i);
					x_k += (1<<i);
					temp = temp->right;
				} else {
					// temp node doesn't have a right child, threfore ith bit of XOR is 0
					temp = temp->left;
				}
			} else {
				// ith bit of n is 1
				if(temp->left) {
					// temp node has a left child, therefore the ith bit of XOR can be 1
					XOR += (1<<i);
					temp = temp->left;
				} else {
					// temp node doesn't have a left child, therefore ith bit of XOR is 0
					temp = temp->right;
					x_k += (1<<i);
				}
			}
		}

		cout << "maxXOR(" << n << ", " << x_k << ") : " << XOR << endl;

		return XOR;
	}

	int maximumXOR(int A[], int n) {
		int finalAns = 0;
		for(int i=0; i<n; i++) {
			finalAns = max(finalAns, helper(A[i]));
		}
		return finalAns;
	}

};

int main() {

	int A[] = {10, 2, 8, 5, 3};
	int n = sizeof(A) / sizeof(int);

	trie t;

	for(int i=0; i<n; i++) {
		t.insert(A[i]);
	}

	cout << t.maximumXOR(A, n) << endl;

	return 0;
}



