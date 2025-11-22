#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    vector<vector<int>> adj(n);
    cout << "Enter edges (u v):\n";
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal: ";
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int x : adj[node]) {
            if(!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
    return 0;
}
