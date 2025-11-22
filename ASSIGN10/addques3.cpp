#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {1, 7, 1};
    vector<int> b = {7, 7, 1};

    if (a.size() != b.size()) {
        cout << "false";
        return 0;
    }

    unordered_map<int, int> freq;

    for (int x : a)
        freq[x]++;

    for (int x : b) {
        if (freq.find(x) == freq.end() || freq[x] == 0) {
            cout << "false";
            return 0;
        }
        freq[x]--;
    }

    cout << "true";
    return 0;
}
