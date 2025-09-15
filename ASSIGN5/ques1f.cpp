#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void deleteNode(Node*& head, int key) {
    if (head == NULL) return;
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) temp = temp->next;
    if (temp->next == NULL) return;
    Node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node{10, new Node{20, new Node{30, NULL}}};
    deleteNode(head, 20);  
    display(head);  
    return 0;
}
