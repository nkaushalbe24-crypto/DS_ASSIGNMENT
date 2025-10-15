#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


int getSize(Node* head) {
    if (head == NULL)
        return 0;

    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

int main() {
    
    Node* head = new Node{10, NULL};
    Node* second = new Node{20, NULL};
    Node* third = new Node{30, NULL};

    head->next = second;
    second->next = third;
    third->next = head;

    cout << "Size of Circular Linked List = " << getSize(head) << endl;

    return 0;
}
