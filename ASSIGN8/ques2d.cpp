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


Node* minValue(Node* node) {
Node* current = node;
while (current && current->left != NULL)
current = current->left;
return current;
}


Node* inorderSuccessor(Node* root, Node* target) {
Node* successor = NULL;
while (root) {
if (target->data < root->data) {
successor = root;
root = root->left;
} else if (target->data > root->data)
root = root->right;
else break;
}
if (root && root->right)
successor = minValue(root->right);
return successor;
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
Node* succ = inorderSuccessor(root, target);
if (succ)
cout << "Inorder Successor: " << succ->data;
else
cout << "No Successor";
}