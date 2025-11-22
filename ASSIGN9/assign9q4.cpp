#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cout << "Enter vertices & edges: ";
    cin >> n >> e;

    vector<vector<pair<int,int>>> adj(n);
    cout << "Enter u v w:\n";
    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        for(auto &p : adj[u]) {
            int v = p.first, w = p.second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from source:\n";
    for(int i = 0; i < n; i++)
        cout << "To " << i << " = " << dist[i] << "\n";
}
