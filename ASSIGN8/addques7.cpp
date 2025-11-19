#include <iostream>
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

Node* insertBST(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insertBST(root->left, key);
    else root->right = insertBST(root->right, key);
    return root;
}

void bstToDLL(Node* root, Node* &head, Node* &prev) {
    if (!root) return;

    bstToDLL(root->left, head, prev);

    if (prev == NULL)
        head = root;       
    else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    bstToDLL(root->right, head, prev);
}

Node* mergeDLL(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* head = NULL;
    Node* tail = NULL;

    while (a && b) {
        Node* temp;
        if (a->data < b->data) {
            temp = a;
            a = a->right;
        } else {
            temp = b;
            b = b->right;
        }

        if (!head)
            head = tail = temp;
        else {
            tail->right = temp;
            temp->left = tail;
            tail = temp;
        }
    }

    while (a) {
        tail->right = a;
        a->left = tail;
        tail = a;
        a = a->right;
    }

    while (b) {
        tail->right = b;
        b->left = tail;
        tail = b;
        b = b->right;
    }

    return head;
}

Node* mergeTwoBSTs(Node* root1, Node* root2) {
    Node* head1 = NULL;
    Node* prev1 = NULL;
    bstToDLL(root1, head1, prev1);

    Node* head2 = NULL;
    Node* prev2 = NULL;
    bstToDLL(root2, head2, prev2);

    return mergeDLL(head1, head2);
}


void printDLL(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;
    root1 = insertBST(root1, 10);
    root1 = insertBST(root1, 5);
    root1 = insertBST(root1, 1);
    root1 = insertBST(root1, 7);
    root2 = insertBST(root2, 8);
    root2 = insertBST(root2, 6);
    root2 = insertBST(root2, 9);
    root2 = insertBST(root2, 12);

    Node* head = mergeTwoBSTs(root1, root2);

    cout << "Merged DLL: ";
    printDLL(head);

    return 0;
}
