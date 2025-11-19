#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) { data = x; left = right = NULL; }
};

Node* buildTreePreIn(int pre[], int in[], int &preIndex, int inStart, int inEnd, unordered_map<int,int> &mp) {
    if (inStart > inEnd) return NULL;

    int rootVal = pre[preIndex++];
    Node* root = new Node(rootVal);

    int pos = mp[rootVal];

    root->left = buildTreePreIn(pre, in, preIndex, inStart, pos - 1, mp);
    root->right = buildTreePreIn(pre, in, preIndex, pos + 1, inEnd, mp);

    return root;
}

Node* buildTree(int pre[], int in[], int n) {
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++) mp[in[i]] = i;

    int preIndex = 0;
    return buildTreePreIn(pre, in, preIndex, 0, n - 1, mp);
}
