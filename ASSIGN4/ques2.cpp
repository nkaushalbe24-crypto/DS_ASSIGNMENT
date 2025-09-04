#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;
public:
    CircularQueue() { front = rear = -1; }

    bool isEmpty() { return (front == -1); }
    bool isFull() { return ((rear + 1) % SIZE == front); }

    void enqueue(int x) {
        if (isFull()) cout << "Queue is Full\n";
        else {
            if (front == -1) front = 0;
            rear = (rear + 1) % SIZE;
            arr[rear] = x;
            cout << x << " enqueued\n";
        }
    }

    void dequeue() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else {
            cout << arr[front] << " dequeued\n";
            if (front == rear) front = rear = -1;
            else front = (front + 1) % SIZE;
        }
    }

    void peek() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else cout << "Front element: " << arr[front] << "\n";
    }

    void display() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else {
            cout << "Queue: ";
            int i = front;
            while (true) {
                cout << arr[i] << " ";
                if (i == rear) break;
                i = (i + 1) % SIZE;
            }
            cout << "\n";
        }
    }
};

int main() {
    CircularQueue cq;

    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.display();

    cq.dequeue();
    cq.display();

    cq.enqueue(4);
    cq.enqueue(5);
    cq.display();

    cq.peek();

    return 0;
}
