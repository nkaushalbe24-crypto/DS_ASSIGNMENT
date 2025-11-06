#include <iostream>
#include <algorithm>
using namespace std;


struct Node {
int data; Node *left, *right;
Node(int val) { data = val; left = right = NULL; }
};


Node* insert(Node* root, int val) {
if (!root) return new Node(val);
if (val < root->data) root->left = insert(root->left, val);
else root->right = insert(root->right, val);
return root;
}


int minDepth(Node* root) {
if (!root) return 0;
if (!root->left) return 1 + minDepth(root->right);
if (!root->right) return 1 + minDepth(root->left);
return 1 + min(minDepth(root->left), minDepth(root->right));
}


int main() {
Node* root = NULL;
root = insert(root, 3);
insert(root, 9);
insert(root, 20);
insert(root, 15);
insert(root, 7);
cout << "Minimum Depth: " << minDepth(root);
}