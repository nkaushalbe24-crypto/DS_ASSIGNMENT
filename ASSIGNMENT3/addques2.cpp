#include <iostream>
#include <stack>
using namespace std;

struct MyStack {
    stack<long long> s;
    long long minEle;

    void push(int x) {
        if(s.empty()) {
            minEle = x;
            s.push(x);
        } else if(x < minEle) {
            s.push(2LL*x - minEle);
            minEle = x;
        } else {
            s.push(x);
        }
    }

    void pop() {
        if(s.empty()) return;
        long long t = s.top(); s.pop();
        if(t < minEle) minEle = 2LL*minEle - t;
    }

    int top() {
        long long t = s.top();
        return (t < minEle) ? minEle : t;
    }

    int getMin() { return minEle; }
};

int main() {
    MyStack ms;
    ms.push(3);
    ms.push(5);
    cout << "Min: " << ms.getMin() << endl;
    ms.push(2);
    ms.push(1);
    cout << "Min: " << ms.getMin() << endl;
    ms.pop();
    cout << "Min: " << ms.getMin() << endl;
}