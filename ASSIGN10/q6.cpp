#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

bool findDuplicates(Node* root, unordered_set<int>& s) {
    if(root == NULL)
        return false;

    if(s.find(root->data) != s.end())
        return true; 
    s.insert(root->data);

    return findDuplicates(root->left, s) || findDuplicates(root->right, s);
}

int main() {
    
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    unordered_set<int> s;

    if(findDuplicates(root, s))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";

    return 0;
}
