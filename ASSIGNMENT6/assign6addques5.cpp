#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *next, *prev, *up, *down;
    Node(int val) {
        data = val;
        next = prev = up = down = NULL;
    }
};

Node*** matrixTo4WayDLL(vector<vector<int>>& mat, int rows, int cols) 
    Node*** nodes = new Node**[rows];
    for (int i = 0; i < rows; i++) {
        nodes[i] = new Node*[cols];
        for (int j = 0; j < cols; j++) {
            nodes[i][j] = new Node(mat[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j + 1 < cols) nodes[i][j]->next = nodes[i][j + 1];
            if (j - 1 >= 0) nodes[i][j]->prev = nodes[i][j - 1];
            if (i - 1 >= 0) nodes[i][j]->up = nodes[i - 1][j];
            if (i + 1 < rows) nodes[i][j]->down = nodes[i + 1][j];
        }
    }

    return nodes; 

void print4WayDLL(Node*** nodes, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        Node* temp = nodes[i][0];
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int rows = mat.size();
    int cols = mat[0].size();

    Node*** nodes = matrixTo4WayDLL(mat, rows, cols);

    cout << "4-way Doubly Linked List (row-wise):\n";
    print4WayDLL(nodes, rows, cols);

    return 0;
}
