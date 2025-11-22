#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int nums[n];
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    unordered_map<int, int> freq;

    for(int i = 0; i < n; i++) {
        freq[nums[i]]++;
    }

    cout << "Frequency of each number:\n";
    for(auto x : freq) {
        cout << x.first << " → " << x.second << " times\n";
    }

    return 0;
}
