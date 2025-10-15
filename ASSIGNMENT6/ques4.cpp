#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL)
        return true;

    Node* left = head;
    Node* right = head;

    
    while (right->next != NULL)
        right = right->next;

    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }

    return true;
}

int main() {
    
    Node* n1 = new Node{'R', NULL, NULL};
    Node* n2 = new Node{'A', n1, NULL};
    Node* n3 = new Node{'D', n2, NULL};
    Node* n4 = new Node{'A', n3, NULL};
    Node* n5 = new Node{'R', n4, NULL};
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    if (isPalindrome(n1))
        cout << "The Doubly Linked List is a Palindrome.";
    else
        cout << "The Doubly Linked List is NOT a Palindrome.";

    return 0;
}
