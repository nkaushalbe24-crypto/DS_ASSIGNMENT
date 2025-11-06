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


Node* maxValue(Node* node) {
Node* current = node;
while (current && current->right != NULL)
current = current->right;
return current;
}


Node* inorderPredecessor(Node* root, Node* target) {
Node* predecessor = NULL;
while (root) {
if (target->data > root->data) {
predecessor = root;
root = root->right;
} else if (target->data < root->data)
root = root->left;
else break;
}
if (root && root->left)
predecessor = maxValue(root->left);
return predecessor;
}


int main() {
Node* root = NULL;
root = insert(root, 20);
insert(root, 8);
insert(root, 22);
insert(root, 4);
insert(root, 12);
insert(root, 10);
insert(root, 14);


Node* target = root->left->right->right;
Node* pred = inorderPredecessor(root, target);
if (pred)
cout << "Inorder Predecessor: " << pred->data;
else
cout << "No Predecessor";
}