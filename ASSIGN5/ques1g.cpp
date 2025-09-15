#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void searchNode(Node* head, int key) {
    int pos = 1;
    while (head != NULL) {
        if (head->data == key) {
            cout << "Node " << key << " found at position " << pos << endl;
            return;
        }
        head = head->next;
        pos++;
    }
    cout << "Node " << key << " not found" << endl;
}

int main() {
    Node* head = new Node{10, new Node{20, new Node{30, NULL}}};
    searchNode(head, 20);  
    searchNode(head, 40);  
    return 0;
}
