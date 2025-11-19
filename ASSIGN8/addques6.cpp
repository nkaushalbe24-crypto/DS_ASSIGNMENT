#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) { data = x; left = right = NULL; }
};

Node* buildTreeInPost(int in[], int post[], int &postIndex, int inStart, int inEnd, unordered_map<int,int>& mp) {
    if (inStart > inEnd) return NULL;

    int rootVal = post[postIndex--];
    Node* root = new Node(rootVal);

    int pos = mp[rootVal];

    root->right = buildTreeInPost(in, post, postIndex, pos + 1, inEnd, mp);
    root->left = buildTreeInPost(in, post, postIndex, inStart, pos - 1, mp);

    return root;
}

Node* buildTree2(int in[], int post[], int n) {
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++) mp[in[i]] = i;

    int postIndex = n - 1;
    return buildTreeInPost(in, post, postIndex, 0, n - 1, mp);
}
