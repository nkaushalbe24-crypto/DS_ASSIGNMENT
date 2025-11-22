#include <bits/stdc++.h>
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

    vector<bool> selected(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, 0}); 
    int mst = 0;

    cout << "Edges in MST:\n";
    while(!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if(selected[u]) continue;
        selected[u] = true;
        mst += w;
        cout << "Include Vertex: " << u << " Weight: " << w << "\n";

        for(auto &p : adj[u]) {
            if(!selected[p.first])
                pq.push({p.second, p.first});
        }
    }
    cout << "Total Weight = " << mst;
}
