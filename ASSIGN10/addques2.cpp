#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {0, -1, 2, -3, 1}; 
    int target = -2;

    unordered_set<int> s;

    for (int x : arr) {
        int needed = target - x;

        if (s.find(needed) != s.end()) {
            cout << "true";
            return 0;
        }

        s.insert(x);
    }

    cout << "false";
    return 0;
}
