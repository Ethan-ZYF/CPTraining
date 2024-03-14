#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

vector<pair<int, int>> odd, even;

vector<vector<int>> all_comb;

void dfs(int i, vector<int> cur, int last = -1) {
    if (i == 4) {
        all_comb.push_back(cur);
        return;
    }
    for (int j = last + 1; j < 25; j++) {
        cur.push_back(j);
        dfs(i + 1, cur, j);
        cur.pop_back();
    }
}

bool check(vector<vector<int>>& g, int mode) {
    if (mode) {
        for (auto [i, j] : odd) {
            if (i == 0 or i == 6 or j == 0 or j == 6)
                continue;
            if (g[i][j] and g[i - 1][j - 1] and g[i - 1][j + 1] and g[i + 1][j + 1] and g[i + 1][j - 1]) {
                return false;
            }
        }
    } else {
        for (auto [i, j] : even) {
            if (i == 0 or i == 6 or j == 0 or j == 6)
                continue;
            if (g[i][j] and g[i - 1][j - 1] and g[i + 1][j - 1] and g[i + 1][j + 1] and g[i - 1][j + 1]) {
                return false;
            }
        }
    }
    return true;
}

int check1(vector<vector<int>> g) {
    int ans = check(g, 1) ? 0 : 4;
    debug(ans);
    for (auto& v : all_comb) {
        int w = v[0], x = v[1], y = v[2], z = v[3];
        if (max({w, x, y, z}) >= odd.size())
            continue;
        vector<vector<int>> ng = g;
        auto [a1, b1] = odd[w];
        auto [a2, b2] = odd[x];
        auto [a3, b3] = odd[y];
        auto [a4, b4] = odd[z];
        int cur = 0;
        if (ng[a1][b1]) {
            cur++;
            ng[a1][b1] = 0;
        }
        if (ng[a2][b2]) {
            cur++;
            ng[a2][b2] = 0;
        }
        if (ng[a3][b3]) {
            cur++;
            ng[a3][b3] = 0;
        }
        if (ng[a4][b4]) {
            cur++;
            ng[a4][b4] = 0;
        }
        if (check(ng, 1)) {
            ans = min(ans, cur);
        }
    }
    return ans;
}

int check2(vector<vector<int>> g) {
    int ans = check(g, 0) ? 0 : 4;
    debug(ans);
    for (auto& v : all_comb) {
        int w = v[0], x = v[1], y = v[2], z = v[3];
        debug(w, x, y, z);
        if (max({w, x, y, z}) >= even.size())
            continue;
        vector<vector<int>> ng = g;
        auto [a1, b1] = even[w];
        auto [a2, b2] = even[x];
        auto [a3, b3] = even[y];
        auto [a4, b4] = even[z];
        int cur = 0;
        if (ng[a1][b1]) {
            cur++;
            ng[a1][b1] = 0;
        }
        if (ng[a2][b2]) {
            cur++;
            ng[a2][b2] = 0;
        }
        if (ng[a3][b3]) {
            cur++;
            ng[a3][b3] = 0;
        }
        if (ng[a4][b4]) {
            cur++;
            ng[a4][b4] = 0;
        }
        if (check(ng, 0)) {
            ans = min(ans, cur);
        }
    }
    return ans;
}

void solve() {
    vector<vector<int>> g(7, vector<int>(7));
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            char c;
            cin >> c;
            g[i][j] = c == 'B';
        }
    }
    debug(g);
    int c1 = check1(g), c2 = check2(g);
    debug(c1, c2);
    cout << c1 + c2 << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    dfs(0, {});
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if ((i + j) % 2 == 1)
                odd.push_back({i, j});
            else
                even.push_back({i, j});
        }
    }
    // debug(odd);
    // debug(even);
    debug(all_comb.size());
    debug(odd.size(), even.size());
    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}