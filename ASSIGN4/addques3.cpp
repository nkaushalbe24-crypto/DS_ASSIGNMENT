#include <bits/stdc++.h>
using namespace std;

bool checkSorted(queue<int>& q) {
    stack<int> st;
    int expected = 1, n = q.size();
    while (!q.empty()) {
        if (q.front() == expected) {
            q.pop(); expected++;
        } else if (!st.empty() && st.top() == expected) {
            st.pop(); expected++;
        } else {
            st.push(q.front()); q.pop();
        }
    }
    while (!st.empty()) {
        if (st.top() != expected) return false;
        st.pop(); expected++;
    }
    return true;
}

int main() {
    queue<int> q;
    q.push(5); q.push(1); q.push(2); q.push(3); q.push(4);
    if (checkSorted(q)) cout << "Yes";
    else cout << "No";
    return 0;
}
