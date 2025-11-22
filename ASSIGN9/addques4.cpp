#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
int m, n;
bool vis[100][100];

void dfs(int r, int c) {
    if (r < 0 || c < 0 || r >= m || c >= n) return;
    if (grid[r][c] == 0 || vis[r][c]) return;

    vis[r][c] = true;
    dfs(r+1, c);
    dfs(r-1, c);
    dfs(r, c+1);
    dfs(r, c-1);
}

int main() {
    cin >> m >> n;
    grid.assign(m, vector<int>(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !vis[i][j]) {
                dfs(i, j);
                count++;
            }
        }
    }
    cout << count;
}
