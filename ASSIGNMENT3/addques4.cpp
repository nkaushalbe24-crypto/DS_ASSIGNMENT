#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cout << "Enter days: ";
    cin >> n;
    vector<int> temp(n), ans(n, 0);
    cout << "Enter temperatures: ";
    for(int i=0; i<n; i++) cin >> temp[i];

    stack<int> st; 
    for(int i=0; i<n; i++) {
        while(!st.empty() && temp[i] > temp[st.top()]) {
            int idx = st.top(); st.pop();
            ans[idx] = i - idx;
        }
        st.push(i);
    }

    cout << "Wait days: ";
    for(int x : ans) cout << x << " ";
}