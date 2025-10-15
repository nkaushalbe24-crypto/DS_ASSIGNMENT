#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyList {
    Node* head;

public:
    DoublyList() { head = NULL; }
    void insertAtBeginning(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = head;

        if (head != NULL)
            head->prev = newNode;

        head = newNode;
        cout << "Inserted " << value << " at beginning.\n";
    }

    
    void insertAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
            cout << "Inserted " << value << " at end.\n";
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
        cout << "Inserted " << value << " at end.\n";
    }

    void insertAfter(int key, int value) {
        Node* temp = head;
        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Node " << key << " not found.\n";
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = newNode;

        temp->next = newNode;
        cout << "Inserted " << value << " after " << key << ".\n";
    }

    void deleteNode(int key) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;

        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Node " << key << " not found.\n";
            return;
        }

        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        delete temp;
        cout << "Deleted node " << key << ".\n";
    }

   
    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << key << " not found.\n";
    }

  
    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Doubly List (forward): ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyList list;
    int choice, value, key;

    do {
    
        cout << " Insert at Beginning\n";
        cout << " Insert at End\n";
        cout << " Insert After a Node\n";
        cout << " Delete a Node\n";
        cout << " Search a Node\n";
        cout << " Display List\n";
        cout << " Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter key(after which to insert): ";
            cin >> key;
            cout << "Enter value: ";
            cin >> value;
            list.insertAfter(key, value);
            break;
        case 4:
            cout << "Enter value to delete: ";
            cin >> key;
            list.deleteNode(key);
            break;
        case 5:
            cout << "Enter value to search: ";
            cin >> key;
            list.search(key);
            break;
        case 6:
            list.display();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
