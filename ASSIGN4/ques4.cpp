#include <iostream>
#include <queue>
using namespace std;

void firstNonRepeating(string str) {
    int freq[26] = {0};
    queue<char> q;

    for (char ch : str) {
        freq[ch - 'a']++;
        q.push(ch);

        while (!q.empty() && freq[q.front() - 'a'] > 1)
            q.pop();

        if (q.empty()) cout << -1 << " ";
        else cout << q.front() << " ";
    }
}

int main() {
    string s = "aabc";

    cout << "Input: " << s << "\n";
    cout << "Output: ";
    firstNonRepeating(s);

    return 0;
}
