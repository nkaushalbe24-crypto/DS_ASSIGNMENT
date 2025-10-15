#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void splitList(Node* head, Node** head1_ref, Node** head2_ref) {
    if (head == NULL)
        return;

    Node* slow = head;
    Node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    if (fast->next->next == head)
        fast = fast->next;

    *head1_ref = head;
    *head2_ref = slow->next;

    fast->next = slow->next;
    slow->next = head;
}

void printList(Node* head) {
    if (head == NULL)
        return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    
    Node* head = new Node{10, NULL};
    Node* second = new Node{4, NULL};
    Node* third = new Node{9, NULL};

    head->next = second;
    second->next = third;
    third->next = head; // circular link

    Node* head1 = NULL;
    Node* head2 = NULL;

    splitList(head, &head1, &head2);

    cout << "First half: ";
    printList(head1);

    cout << "Second half: ";
    printList(head2);

    return 0;
}
