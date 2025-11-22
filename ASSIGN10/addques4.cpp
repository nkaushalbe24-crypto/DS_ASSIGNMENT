#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* insert(Node* head, int x) {
    Node* temp = new Node(x);
    temp->next = head;
    return temp;
}

int main() {
    Node* head1 = new Node(10);
    head1->next = new Node(15);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(20);

    Node* head2 = new Node(8);
    head2->next = new Node(4);
    head2->next->next = new Node(2);
    head2->next->next->next = new Node(10);

    unordered_set<int> s;
    Node *unionList = NULL, *intersectionList = NULL;

    for (Node* cur = head1; cur != NULL; cur = cur->next) {
        s.insert(cur->data);
        unionList = insert(unionList, cur->data);
    }

    unordered_set<int> s2;
    for (Node* cur = head2; cur != NULL; cur = cur->next) {
        if (s.find(cur->data) != s.end())
            intersectionList = insert(intersectionList, cur->data);
        if (s2.find(cur->data) == s2.end()) {
            unionList = insert(unionList, cur->data);
            s2.insert(cur->data);
        }
    }

    cout << "Intersection List: ";
    for (Node* cur = intersectionList; cur != NULL; cur = cur->next)
        cout << cur->data << " ";
    cout << endl;

    cout << "Union List: ";
    for (Node* cur = unionList; cur != NULL; cur = cur->next)
        cout << cur->data << " ";
    cout << endl;

    return 0;
}
