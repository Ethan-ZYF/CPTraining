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
    vector grid(n, vector(m, 0));
    for (auto& row : grid) {
        for (auto& x : row) {
            cin >> x;
        }
    }
    auto manhattan = [&](int i1, int j1, int i2, int j2) -> int {
        return abs(i1 - i2) + abs(j1 - j2);
    };
    int ans = 0;
    vector<array<int, 2>> diff((n + m - 1) / 2 + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int d1 = manhattan(i, j, 0, 0);
            int d2 = manhattan(i, j, n - 1, m - 1);
            if (d1 == d2) continue;
            if (d1 < d2)
                diff[d1][grid[i][j]]++;
            else
                diff[d2][grid[i][j]]++;
        }
    }
    for (auto& d : diff) {
        ans += min(d[0], d[1]);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}