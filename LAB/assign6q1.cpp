#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularList {
    Node* head;

public:
    CircularList() { head = NULL; }

    void insertAtBeginning(int value) {
        Node* newNode = new Node;
        newNode->data = value;

        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        cout << "Inserted " << value << " at beginning.\n";
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;

        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Inserted " << value << " at end.\n";
    }

    void insertAfter(int key, int value) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node;
                newNode->data = value;
                newNode->next = temp->next;
                temp->next = newNode;
                cout << "Inserted " << value << " after " << key << ".\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << key << " not found.\n";
    }

    void deleteNode(int key) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* curr = head;
        Node* prev = NULL;

        if (head->data == key) {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            if (head->next == head) {
                delete head;
                head = NULL;
            } else {
                temp->next = head->next;
                delete head;
                head = temp->next;
            }
            cout << "Deleted node " << key << ".\n";
            return;
        }

        do {
            prev = curr;
            curr = curr->next;
            if (curr->data == key) {
                prev->next = curr->next;
                delete curr;
                cout << "Deleted node " << key << ".\n";
                return;
            }
        } while (curr != head);

        cout << "Node " << key << " not found.\n";
    }

    void search(int key) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);

        cout << "Node " << key << " not found.\n";
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Circular List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularList list;
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
