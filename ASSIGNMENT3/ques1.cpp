#include <iostream>
using namespace std;

#define SIZE 100

struct stack {
    int arr[SIZE];
    int top;

public:
    stack() { top = -1; }

    bool isfull() {
        return top == SIZE - 1;
    }

    bool isempty() {
        return top == -1;
    }

    void push(int x) {
        if (isfull()) {
            cout << "Overflow!" << endl;
            return;
        }
        arr[++top] = x;
        cout << x << " pushed" << endl;
    }

    void pop() {
        if (isempty()) {
            cout << "Underflow!" << endl;
            return;
        }
        cout << arr[top--] << " popped" << endl;
    }

    void display() {
        if (isempty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};