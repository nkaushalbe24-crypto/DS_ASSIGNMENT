#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->prev = temp->next = NULL;
    return temp;
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

void correctRandomPointer(Node* head) {
    if (!head) return;

    Node* temp = head;
    while (temp->next && temp->next->prev == temp)
        temp = temp->next;

    
    if (temp->next != NULL) {
        cout << "\nWrong link detected at node with data: " << temp->data << endl;

        
        Node* fix = temp;
        while (fix->next != NULL && fix->next != head && fix->next->prev == fix)
            fix = fix->next;

        temp->next = NULL;

        cout << "Fixed the random pointer.\n";
    }
}

int main() {
    Node* head = newNode(10);
    Node* n2 = newNode(20);
    Node* n3 = newNode(30);
    Node* n4 = newNode(40);

    head->next = n2;
    n2->prev = head;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;

    n4->next = n2;  

    cout << "Before fixing:\n";
    cout << "(Traversing first few nodes to show loop)\n";
    Node* temp = head;
    for (int i = 0; i < 6 && temp; i++) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
   
    correctRandomPointer(head);

    cout << "\nAfter fixing:\n";
    printList(head);

    return 0;
}
