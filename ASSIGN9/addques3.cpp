#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, E, K;
    cin >> N >> E >> K;

    vector<vector<pair<int,int>>> graph(N+1);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vector<int> dist(N+1, 1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[K] = 0;
    pq.push({0, K});

    while (!pq.empty()) {
        auto [cost, node] = pq.top(); pq.pop();
        for (auto [next, w] : graph[node]) {
            if (cost + w < dist[next]) {
                dist[next] = cost + w;
                pq.push({dist[next], next});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans = max(ans, dist[i]);

    if (ans == 1e9) cout << -1;
    else cout << ans;
}
