#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isCircular(Node* head) {
    if (head == NULL)
        return false;

    Node* temp = head->next;

    while (temp != NULL && temp != head)
        temp = temp->next;

    return (temp == head);
}

int main() {
    Node* head = new Node{10, NULL};
    Node* second = new Node{20, NULL};
    Node* third = new Node{30, NULL};

    head->next = second;
    second->next = third;
    third->next = NULL;

    if (isCircular(head))
        cout << "The Linked List is Circular.";
    else
        cout << "The Linked List is NOT Circular.";

    return 0;
}


