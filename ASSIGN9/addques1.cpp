#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> vis;

void dfs(int node) {
    vis[node] = true;
    for (int child : graph[node])
        if (!vis[child])
            dfs(child);
}

int main() {
    int V, E;
    cin >> V >> E;

    graph.resize(V);
    vis.resize(V, false);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int components = 0;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i);
            components++;
        }
    }

    cout << "Number of connected components = " << components;
    return 0;
}
