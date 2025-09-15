#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> A(n), ans;
    cout << "Enter elements: ";
    for(int i=0; i<n; i++) cin >> A[i];

    stack<int> st;

    for(int i=0; i<n; i++) {
        while(!st.empty() && st.top() >= A[i]) st.pop();
        if(st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());
        st.push(A[i]);
    }

    cout << "Nearest smaller elements: ";
    for(int x : ans) cout << x << " ";
}