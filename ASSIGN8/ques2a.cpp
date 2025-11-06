#include <iostream>
using namespace std;


struct Node {
int data;
Node *left, *right;
Node(int val) { data = val; left = right = NULL; }
};


Node* insert(Node* root, int val) {
if (root == NULL) return new Node(val);
if (val < root->data)
root->left = insert(root->left, val);
else if (val > root->data)
root->right = insert(root->right, val);
return root;
}


Node* searchRecursive(Node* root, int key) {
if (root == NULL || root->data == key) return root;
if (key < root->data) return searchRecursive(root->left, key);
else return searchRecursive(root->right, key);
}


Node* searchIterative(Node* root, int key) {
while (root != NULL && root->data != key) {
if (key < root->data) root = root->left;
else root = root->right;
}
return root;
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


int key = 60;
cout << (searchRecursive(root, key) ? "Found Recursively" : "Not Found") << endl;
cout << (searchIterative(root, key) ? "Found Iteratively" : "Not Found") << endl;
}