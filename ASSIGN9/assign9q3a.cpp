#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int find(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x], parent);
}

void unionSet(int a, int b, vector<int>& parent) {
    a = find(a, parent);
    b = find(b, parent);
    parent[b] = a;
}

int main() {
    int n, e;
    cout << "Enter vertices & edges: ";
    cin >> n >> e;

    vector<Edge> edges(e);
    cout << "Enter u v w:\n";
    for(int i = 0; i < e; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n);
    for(int i = 0; i < n; i++) parent[i] = i;

    int mst = 0;
    cout << "Edges in MST:\n";
    for(auto &ed : edges) {
        if(find(ed.u, parent) != find(ed.v, parent)) {
            cout << ed.u << " - " << ed.v << " : " << ed.w << "\n";
            mst += ed.w;
            unionSet(ed.u, ed.v, parent);
        }
    }
    cout << "Total Weight = " << mst;
}
