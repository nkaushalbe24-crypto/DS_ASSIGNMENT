#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    cout << "Enter size of first array: ";
    cin >> n;
    cout << "Enter size of second array: ";
    cin >> m;

    int A[n], B[m];
    cout << "Enter first array elements: ";
    for(int i = 0; i < n; i++)
        cin >> A[i];

    cout << "Enter second array elements: ";
    for(int i = 0; i < m; i++)
        cin >> B[i];

    unordered_set<int> s;

    for(int i = 0; i < n; i++)
        s.insert(A[i]);

    cout << "Common elements: ";
    bool found = false;

    for(int i = 0; i < m; i++) {
        if(s.find(B[i]) != s.end()) {  
            cout << B[i] << " ";
            found = true;
        }
    }

    if(!found)
        cout << "No common elements";

    return 0;
}
