#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

constexpr int MOD = 1e9 + 7;
i64 p2v(pair<i64, i64> p) {
    auto [x, y] = p;
    return x * MOD + y;
}

pair<i64, i64> v2p(i64 v) {
    return {v / MOD, v % MOD};
}

void solve() {
    int nt, ns, r;
    cin >> nt >> ns >> r;
    vector<pair<int, int>> tree(nt), sens(ns);
    for (auto& [x, y] : tree) {
        cin >> x >> y;
    }
    for (auto& [x, y] : sens) {
        cin >> x >> y;
        if(x == 0 and y == 0) {
            cout << "Impossible\n";
            return;
        }
    }
    int rcc = 0;
    int _ = 4;
    int resx = 0, resy = 0;
    while (_--) {
        for (auto& [x, y] : sens) {
            int nx = -y, ny = x;
            x = nx, y = ny;
        }

        std::unordered_map<long long, int> cnt;
        for (auto& [sx, sy] : sens) {
            for (auto& [tx, ty] : tree) {
                int dx = tx - sx, dy = ty - sy;
                // robot position
                cnt[p2v({dx, dy})]++;
            }
        }
        for (auto& [v, c] : cnt) {
            if (c != ns) continue;
            auto [rx, ry] = v2p(v);
            int count_in_r = 0;
            for (auto& [tx, ty] : tree) {
                int dx = tx - rx, dy = ty - ry;
                if (abs(dx) + abs(dy) <= r) {
                    count_in_r++;
                }
            }
            if (count_in_r == ns) {
                rcc++;
                if (rcc > 1) {
                    cout << "Ambiguous\n";
                    return;
                }
                debug(rx, ry);
                resx = rx, resy = ry;
            }
        }
    }
    if (rcc == 0) {
        cout << "Impossible\n";
    } else if (rcc == 1) {
        cout << resx << " " << resy << "\n";
    } else {
        cout << "Ambiguous\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    // cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}