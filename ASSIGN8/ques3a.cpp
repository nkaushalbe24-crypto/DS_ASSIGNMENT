#include <iostream>
using namespace std;


struct Node {
int data; Node *left, *right;
Node(int val) { data = val; left = right = NULL; }
};


Node* insert(Node* root, int val) {
if (!root) return new Node(val);
if (val < root->data)
root->left = insert(root->left, val);
else if (val > root->data)
root->right = insert(root->right, val);
return root;
}


void inorder(Node* root) {
if (!root) return;
inorder(root->left);
cout << root->data << " ";
inorder(root->right);
}


int main() {
Node* root = NULL;
root = insert(root, 50);
insert(root, 30);
insert(root, 70);
insert(root, 60);
insert(root, 80);
inorder(root);
}