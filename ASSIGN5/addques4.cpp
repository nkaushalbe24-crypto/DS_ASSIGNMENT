#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Insert node at end
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

Node* rotateLeft(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

   
    int len = 1;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }

    k = k % len;
    if (k == 0) return head;


    Node* temp = head;
    for (int i = 1; i < k; i++) temp = temp->next;

    
    Node* newHead = temp->next;
    temp->next = NULL;   
    tail->next = head;   
    return newHead;
}


void display(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    for (int i = 1; i <= 6; i++) insertEnd(head, i);

    cout << "Original List: ";
    display(head);

    int k = 2;
    head = rotateLeft(head, k);

    cout << "List after rotating left by " << k << ": ";
    display(head);

    return 0;
}
