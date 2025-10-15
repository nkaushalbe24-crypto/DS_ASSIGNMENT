#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insertEnd(Node** head_ref, int data) {
    Node* newNode = new Node{data, NULL, NULL};
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    Node* temp = *head_ref;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " <=> ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverseInGroups(Node* head, int k) {
    if (!head) return NULL;

    Node* current = head;
    Node* next = NULL;
    Node* newHead = NULL;
    int count = 0;

    while (current != NULL && count < k) {
        next = current->next;
        current->next = current->prev;
        current->prev = next;
        newHead = current;
        current = next;
        count++;
    }

    if (current != NULL) {
        Node* restHead = reverseInGroups(current, k);
        head->next = restHead;
        if (restHead != NULL)
            restHead->prev = head;
    }

    return newHead;
}

int main() {
    Node* head = NULL;
    insertEnd(&head, 10);
    insertEnd(&head, 8);
    insertEnd(&head, 4);
    insertEnd(&head, 2);
    insertEnd(&head, 5);
    insertEnd(&head, 1);
    insertEnd(&head, 6);

    int k = 3;

    cout << "Original Doubly Linked List:\n";
    printList(head);

    head = reverseInGroups(head, k);

    cout << "\nAfter reversing in groups of " << k << ":\n";
    printList(head);

    return 0;
}
