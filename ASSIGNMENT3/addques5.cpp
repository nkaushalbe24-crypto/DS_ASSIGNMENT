#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];

    stack<int> st;
    vector<int> B;
    int need = 1; 

    for(int i=0; i<n; i++) {
        st.push(A[i]);
        while(!st.empty() && st.top() == need) {
            B.push_back(st.top());
            st.pop();
            need++;
        }
    }

    if(B.size() == n) cout << "Yes, possible" << endl;
    else cout << "No, not possible" << endl;
}