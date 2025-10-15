#include <iostream>
using namespace std;

int countOnes(int n) {
    int count = 0;
    while (n) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

void removeEvenParity(DNode** head_ref) {
    DNode* temp = *head_ref;

    while (temp) {
        int ones = countOnes(temp->data);
        if (ones % 2 == 0) { 
            DNode* del = temp;

            if (temp->prev)
                temp->prev->next = temp->next;
            else
                *head_ref = temp->next;

            if (temp->next)
                temp->next->prev = temp->prev;

            temp = temp->next;
            delete del;
        } else {
            temp = temp->next;
        }
    }
}

void printDLL(DNode* head) {
    DNode* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " <=> ";
        temp = temp->next;
    }
    cout << endl;
}

struct CNode {
    int data;
    CNode* next;
};

void removeEvenParityCLL(CNode** head_ref) {
    if (*head_ref == NULL)
        return;

    CNode *curr = *head_ref, *prev = NULL;

    do {
        int ones = countOnes(curr->data);
        if (ones % 2 == 0) { // even parity
            if (curr == *head_ref && curr->next == *head_ref) {
                delete curr;
                *head_ref = NULL;
                return;
            }

            if (curr == *head_ref) {
                prev = *head_ref;
                while (prev->next != *head_ref)
                    prev = prev->next;
                *head_ref = curr->next;
                prev->next = *head_ref;
                delete curr;
                curr = *head_ref;
            } else {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    } while (curr != *head_ref);
}

void printCLL(CNode* head) {
    if (head == NULL)
        return;

    CNode* temp = head;
    do {
        cout << temp->data;
        temp = temp->next;
        if (temp != head)
            cout << " -> ";
    } while (temp != head);
    cout << endl;
}

int main() {
    CNode* headCLL = new CNode{9, NULL};
    CNode* n2 = new CNode{11, NULL};
    CNode* n3 = new CNode{34, NULL};
    CNode* n4 = new CNode{6, NULL};
    CNode* n5 = new CNode{13, NULL};
    CNode* n6 = new CNode{21, NULL};

    headCLL->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = headCLL; 

    cout << "Original: ";
    printCLL(headCLL);

    removeEvenParityCLL(&headCLL);

    cout << "After Removing Even Parity Nodes: ";
    printCLL(headCLL);

    DNode* headDLL = new DNode{18, NULL, NULL};
    DNode* d2 = new DNode{15, headDLL, NULL};
    DNode* d3 = new DNode{8, d2, NULL};
    DNode* d4 = new DNode{9, d3, NULL};
    DNode* d5 = new DNode{14, d4, NULL};

    headDLL->next = d2;
    d2->next = d3;
    d3->next = d4;
    d4->next = d5;

    cout << "Original: ";
    printDLL(headDLL);

    removeEvenParity(&headDLL);

    cout << "After Removing Even Parity Nodes: ";
    printDLL(headDLL);

    return 0;
}
