#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int pow;
    Node* next;
    Node(int c, int p) {
        coeff = c;
        pow = p;
        next = NULL;
    }
};


void insertEnd(Node*& head, int coeff, int pow) {
    Node* newNode = new Node(coeff, pow);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}


Node* addPolynomials(Node* head1, Node* head2) {
    Node* result = NULL;
    Node* temp1 = head1;
    Node* temp2 = head2;

    while (temp1 && temp2) {
        if (temp1->pow == temp2->pow) {
            insertEnd(result, temp1->coeff + temp2->coeff, temp1->pow);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->pow > temp2->pow) {
            insertEnd(result, temp1->coeff, temp1->pow);
            temp1 = temp1->next;
        }
        else {
            insertEnd(result, temp2->coeff, temp2->pow);
            temp2 = temp2->next;
        }
    }

    
    while (temp1) {
        insertEnd(result, temp1->coeff, temp1->pow);
        temp1 = temp1->next;
    }
    while (temp2) {
        insertEnd(result, temp2->coeff, temp2->pow);
        temp2 = temp2->next;
    }

    return result;
}


void display(Node* head) {
    while (head) {
        cout << head->coeff << "x^" << head->pow;
        if (head->next) cout << " + ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    insertEnd(poly1, 5, 2);
    insertEnd(poly1, 4, 1);
    insertEnd(poly1, 2, 0);

    insertEnd(poly2, 5, 1);
    insertEnd(poly2, 5, 0);

    cout << "Polynomial 1: ";
    display(poly1);

    cout << "Polynomial 2: ";
    display(poly2);

    Node* result = addPolynomials(poly1, poly2);

    cout << "Resultant Polynomial: ";
    display(result);

    return 0;
}
