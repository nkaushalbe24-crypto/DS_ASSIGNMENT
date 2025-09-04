#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() { front = -1; rear = -1; }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == SIZE - 1);
    }

    void enqueue(int x) {
        if (isFull())
            cout << "Queue is Full\n";
        else {
            if (front == -1) front = 0;
            arr[++rear] = x;
            cout << x << " enqueued\n";
        }
    }

    void dequeue() {
        if (isEmpty())
            cout << "Queue is Empty\n";
        else {
            cout << arr[front] << " dequeued\n";
            if (front == rear)
                front = rear = -1;
            else
                front++;
        }
    }

    void peek() {
        if (isEmpty())
            cout << "Queue is Empty\n";
        else
            cout << "Front element: " << arr[front] << "\n";
    }

    void display() {
        if (isEmpty())
            cout << "Queue is Empty\n";
        else {
            cout << "Queue: ";
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
            cout << "\n";
        }
    }
};

int main() {
    Queue q;  

   
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.peek();

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    return 0;
}
