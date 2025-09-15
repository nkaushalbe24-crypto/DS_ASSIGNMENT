#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    vector<int> arr(n), ans(n, -1);
    cout << "Enter elements: ";
    for(int i=0; i<n; i++) cin >> arr[i];

    stack<int> st; // will store indices

    for(int i=n-1; i>=0; i--) {
        while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        if(!st.empty()) ans[i] = arr[st.top()];
        st.push(i);
    }

    cout << "Next Greater Elements: ";
    for(int x : ans) cout << x << " ";
}