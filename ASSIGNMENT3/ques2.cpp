#include <iostream>
using namespace std;

#define SIZE 100

class Stack {
    char arr[SIZE];
    int top;

public:
    Stack() { top = -1; }

    bool isFull() {
        return top == SIZE - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(char x) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = x;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return '\0';
        }
        return arr[top--];
    }
};

int main() {
    char str[SIZE];
    cout << "Enter a string: ";
    cin.getline(str, SIZE);

    Stack s;

    for (int i = 0; str[i] != '\0'; i++) {
        s.push(str[i]);
    }

    cout << "Reversed string: ";
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;

    return 0;
}