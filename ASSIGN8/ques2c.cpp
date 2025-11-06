#include <iostream>
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


int findMin(Node* root) {
if (!root) return -1;
while (root->left) root = root->left;
return root->data;
}


int main() {
Node* root = NULL;
root = insert(root, 50);
insert(root, 30);
insert(root, 70);
insert(root, 20);
insert(root, 40);
cout << "Minimum Element: " << findMin(root);
}