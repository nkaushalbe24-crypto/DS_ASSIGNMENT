#include <iostream>
using namespace std;


struct Node {
int data; Node *left, *right;
Node(int val) { data = val; left = right = NULL; }
};


Node* insert(Node* root, int val) {
if (!root) return new Node(val);
if (val < root->data) root->left = insert(root->left, val);
else if (val > root->data) root->right = insert(root->right, val);
return root;
}


Node* findMin(Node* root) {
while (root->left) root = root->left;
return root;
}


Node* deleteNode(Node* root, int key) {
if (!root) return root;
if (key < root->data)
root->left = deleteNode(root->left, key);
else if (key > root->data)
root->right = deleteNode(root->right, key);
else {
if (!root->left) return root->right;
else if (!root->right) return root->left;
Node* temp = findMin(root->right);
root->data = temp->data;
root->right = deleteNode(root->right, temp->data);
}
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
insert(root, 20);
insert(root, 40);
insert(root, 60);
insert(root, 80);
root = deleteNode(root, 20);
inorder(root);
}