#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left] > heap[largest]) largest = left;
        if (right < n && heap[right] > heap[largest]) largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void deleteMax() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!\n";
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int getMax() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        return heap[0];
    }

    void display() {
        cout << "Priority Queue (Max-Heap): ";
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap pq;
    pq.insert(10);
    pq.insert(30);
    pq.insert(20);
    pq.insert(50);
    pq.insert(40);

    pq.display();
    cout << "Max element: " << pq.getMax() << endl;

    pq.deleteMax();
    cout << "After deleting max:\n";
    pq.display();

    return 0;
}
