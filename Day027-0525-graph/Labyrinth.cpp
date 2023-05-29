#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto& s : grid) cin >> s;
    pair<int, int> start = {-1, -1}, end = {-1, -1};
    for (int i = 0; i < n; i++) {
        int j = grid[i].find('A');
        if (j != string::npos) {
            start = {i, j};
        }
        j = grid[i].find('B');
        if (j != string::npos) {
            end = {i, j};
        }
    }
    vector<vector<int>> vis(n, vector<int>(m));
    queue<pair<int, int>> q;
    q.push(start);
    vis[start.first][start.second] = 1;
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    string s = "RLDU";
    vector<vector<int>> pre(n, vector<int>(m, -1));
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i].first, ny = y + dir[i].second;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] || grid[nx][ny] == '#') continue;
            vis[nx][ny] = 1;
            pre[nx][ny] = i;
            q.push({nx, ny});
        }
    }
    if (vis[end.first][end.second]) {
        cout << "YES\n";
        string ans;
        while (end != start) {
            int i = pre[end.first][end.second];
            ans += s[i];
            end.first -= dir[i].first;
            end.second -= dir[i].second;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        cout << ans << '\n';
        return;
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}