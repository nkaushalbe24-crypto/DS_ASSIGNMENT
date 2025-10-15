#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

int getSize(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
  
    Node* head = new Node{10, NULL, NULL};
    Node* second = new Node{20, head, NULL};
    Node* third = new Node{30, second, NULL};

   
    head->next = second;
    second->next = third;

    cout << "Size of Doubly Linked List = " << getSize(head) << endl;

    return 0;
}
