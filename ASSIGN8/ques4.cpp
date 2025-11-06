#include <iostream>
using namespace std;


struct Node {
int data; Node *left, *right;
Node(int val) { data = val; left = right = NULL; }
};


bool isBSTUtil(Node* root, Node* &prev) {
if (!root) return true;
if (!isBSTUtil(root->left, prev)) return false;
if (prev && root->data <= prev->data) return false;
prev = root;
return isBSTUtil(root->right, prev);
}


bool isBST(Node* root) {
Node* prev = NULL;
return isBSTUtil(root, prev);
}


int main() {
Node* root = new Node(4);
root->left = new Node(2);
root->right = new Node(5);
root->left->left = new Node(1);
root->left->right = new Node(3);
cout << (isBST(root) ? "Is a BST" : "Not a BST");
}